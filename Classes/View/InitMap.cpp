//2151396 �ž���

#include"cocos2d.h"
#include "View\GameScene.h"
#include "Const/Const.h"
#include <algorithm>

using namespace std;
USING_NS_CC;

/**
* @brief ��ʼ����ͼ���ݴԣ��ϰ���
*/
void GameScene::addMap(int chooseNum)
{
    string mapChooseStr;
    if (chooseNum == 1)
        mapChooseStr = Path::map1;
    else if (chooseNum == 2)
        mapChooseStr = Path::map2;
    else if (chooseNum == 3)
        mapChooseStr = Path::map3;

    _mapinfo._map = TMXTiledMap::create(mapChooseStr);
    _mapinfo._map->setAnchorPoint(Vec2::ZERO);
    _mapinfo._map->setPosition(Vec2::ZERO);
    this->addChild(_mapinfo._map, kMapPriority);

    //���ϰ�����ʾ��global
    _mapinfo._obstacleLayer = _mapinfo._map->getLayer("1");
    _mapinfo._obstacleLayer->setGlobalZOrder(kTMXlayer);
    _mapinfo._obstacleLayer = _mapinfo._map->getLayer("2");
    _mapinfo._obstacleLayer->setGlobalZOrder(kTMXlayer);
    _mapinfo._obstacleLayer = _mapinfo._map->getLayer("3");
    _mapinfo._obstacleLayer->setGlobalZOrder(kTMXlayer);

    //��ͼ��������
    _mapinfo._mapTiledNum = _mapinfo._map->getMapSize();
    //�������Ӵ�С
    _mapinfo._tiledSize = _mapinfo._map->getTileSize();
    //��ʼ������
}


Vec2 GameScene::tiledCoordFromPosition(Vec2 position)
{
    int mpx = _mapinfo._tiledSize.width * _mapinfo._mapTiledNum.width;
    int mpy = _mapinfo._tiledSize.height * _mapinfo._mapTiledNum.height;
    //opengl����
    Vec2 posInMap = Vec2(position.x, position.y);
    //UI��������
    Vec2 posInMapUI = Vec2(position.x, mpy - position.y);

    //ת������Ƭ����
    int x = posInMapUI.x / _mapinfo._tiledSize.width;
    int y = posInMapUI.y / _mapinfo._tiledSize.height;

    return Vec2(x, y);
}

Vec2 GameScene::destPos(Point position)
{
    //��Ļ��С
    Size visibleSize = Director::getInstance()->getVisibleSize();

    //��ͼ��С
    Size mapSize = Size(_mapinfo._mapTiledNum.width * _mapinfo._tiledSize.width, _mapinfo._mapTiledNum.height * _mapinfo._tiledSize.height);

    //�������� 
    Point playerPos = position;

    //�����������С����Ļһ�룬��ȡ��Ļ�е�����
    //�㷨
    float x = std::max(playerPos.x, visibleSize.width / 2);
    float y = std::max(playerPos.y, visibleSize.height / 2);

    x = std::min(x, mapSize.width - visibleSize.width / 2);
    y = std::min(y, mapSize.height - visibleSize.height / 2);

    //Ŀ���
    return Vec2(x, y);
}


Vec2 GameScene::randomPosWithoutBarrier()
{
    float x = cocos2d::random(32, maxWidth - 32);
    float y = cocos2d::random(32, maxHeight - 32);

    if (!isGrassExist(Point(x, y)) && !isBarrierExist(Point(x, y)))
        return Vec2(x, y);
    else
        return randomPosWithoutBarrier();
}

void GameScene::setViewPointByPlayer(Point position)
{
    //���鲻���ھ��˳�
    if (_player == nullptr)
        return;

    //��Ļ��С
    Size visibleSize = Director::getInstance()->getVisibleSize();

    //Ŀ���
    Vec2 destPosition = destPos(position);
    //��Ļ�е�
    Vec2 centerPos = Vec2(visibleSize.width / 2, visibleSize.height / 2);

    //��Ļ�е����Ҫ�ƶ���Ŀ���֮��ľ���
    Vec2 viewPos = centerPos - destPosition;
    //log("destPos.x=%f", destPosition.x);
    this->setPosition(viewPos);
}



//��ʼ����ͼ��10��λ��
void GameScene::initObjPosition()
{
    int i = 0;
    auto group = _mapinfo._map->getObjectGroup("initobj");
    ValueVector initobjPos = group->getObjects();
    for (auto posi : initobjPos) 
    {
        ValueMap& dict = posi.asValueMap();
        float x = dict["x"].asFloat();
        float y = dict["y"].asFloat();

        //�Ѷ������ĵ�ַ��������
        _tenPosition.insert(std::pair<int, Vec2>(i,Vec2(x,y)));
        i++;
    }
}


//n��λ�ò���(0~9��
std::vector<int> GameScene::randTenNumberVec(int Num)
{
    vector<int> temp;
    for (int i = 0; i < Num; ++i)
    {
        temp.push_back(i);
    }
    random_shuffle(temp.begin(), temp.end());
    
    return temp;
}

/********************************************************�ݴ�********************************************************/
void GameScene::addGrass()
{
    auto group = _mapinfo._map->getObjectGroup("grass");
    ValueVector grassObjects = group->getObjects();

    for (auto grass : grassObjects)
    {
        ValueMap& dict = grass.asValueMap();
        float x = dict["x"].asFloat();
        float y = dict["y"].asFloat();
        float width = dict["width"].asFloat();
        float height = dict["height"].asFloat();

        PhysicsBody* tmpPhysicsBody = PhysicsBody::createBox(Size(width, height),
            PhysicsMaterial(100.0f, 0.0f, 0.0f));
        tmpPhysicsBody->setDynamic(false);
        //�ݴԵ�
        tmpPhysicsBody->setCategoryBitmask(0x04);
        tmpPhysicsBody->setCollisionBitmask(1);
        tmpPhysicsBody->setContactTestBitmask(0x04);
        tmpPhysicsBody->setGravityEnable(false);

        Sprite* tmpSprite = Sprite::create();
        tmpSprite->setPosition(Vec2(x, y));
        tmpSprite->setAnchorPoint(Vec2::ZERO);
        tmpSprite->setContentSize(Size(width, height));
        tmpSprite->addComponent(tmpPhysicsBody);
        tmpSprite->setTag(kGrassTag);
        tmpSprite->setName(Name::kGrass);

        _grass.pushBack(tmpSprite);
        this->addChild(tmpSprite, kGrassPriority);
    }
}

bool GameScene::isGrassExist(cocos2d::Point position)
{
    for (auto grass : _grass)
    {
        auto grassPos = grass->getPosition() + grass->getContentSize() / 2;
        auto grassSize = grass->getContentSize();
        if ((fabs(grassPos.x - position.x) < grassSize.width / 2) && (fabs(grassPos.y - position.y) < grassSize.height / 2))
        {
            return true;
        }
    }
    return false;
}


Vector<Sprite*> GameScene::getGrass()
{
    return _grass;
}


/********************************************************�ϰ���********************************************************/
void GameScene::addBarrier()
{
    auto group = _mapinfo._map->getObjectGroup("barrier");
    ValueVector barrierObjects = group->getObjects();
    for (auto barrier : barrierObjects)
    {
        ValueMap& dict = barrier.asValueMap();
        float x = dict["x"].asFloat();
        float y = dict["y"].asFloat();
        float width = dict["width"].asFloat();
        float height = dict["height"].asFloat();

        PhysicsBody* tmpPhysicsBody = PhysicsBody::createBox(Size(width, height),PhysicsMaterial(100.0f, 0.0f, 0.0f));
        tmpPhysicsBody->setDynamic(false);
        tmpPhysicsBody->setCategoryBitmask(0x01);
        tmpPhysicsBody->setCollisionBitmask(1);
        tmpPhysicsBody->setContactTestBitmask(0x01);
        tmpPhysicsBody->setGravityEnable(false);

        Sprite* tmpSprite = Sprite::create();       
        tmpSprite->setPosition(Vec2(x, y));
        tmpSprite->setAnchorPoint(Vec2::ZERO);
        tmpSprite->setContentSize(Size(width, height));
        tmpSprite->addComponent(tmpPhysicsBody);
        tmpSprite->setTag(kBarrierTag);
        tmpSprite->setName(Name::kBarrier);

        _obstacle.pushBack(tmpSprite);
        this->addChild(tmpSprite, kBarrierPriority);
    }
}

bool GameScene::isBarrierExist(Point position)
{
    for (auto barrier : _obstacle)
    {
        auto barrierPos = barrier->getPosition() + barrier->getContentSize() / 2;
        auto barrierSize = barrier->getContentSize();
        if ((fabs(barrierPos.x - position.x) < barrierSize.width / 2) && (fabs(barrierPos.y - position.y) < barrierSize.height / 2))
        {
            return true;
        }
    }
    return false;
}

Vector<Sprite*> GameScene::getObstacle()
{
    return _obstacle;
}