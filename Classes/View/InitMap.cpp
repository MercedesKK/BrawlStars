/**
* @author �ž���
* ��ʼ����ͼ���ϰ���
* 
*/
#include"cocos2d.h"
#include "View\GameScene.h"
#include "Const/Const.h"
#include "Tool/TreasureBox.h"
#include "Tool/Item.h"
USING_NS_CC;

void GameScene::initMap()
{
    //��ʼ��������������������������
    _mapinfo._map = TMXTiledMap::create("map/mapNo1.tmx");
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

void  GameScene::addBox()
{
    auto box = TreasureBox::create();
    box->initialzeBloodStrip(kmaxBoxHealthPoint);
    this->addChild(box, kBoxPriority, Name::kTreasureBox);
}

void GameScene::addRandomBox()
{
    const int randomBoxNum = cocos2d::random(18, 23);
    log("create box:%d", randomBoxNum);
    for (int i = 1; i <= randomBoxNum; i++)
    {
        addBox();
    }
}

void GameScene::createBarrier()
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

        PhysicsBody* tmpPhysicsBody = PhysicsBody::createBox(Size(width, height),
        PhysicsMaterial(100.0f, 0.0f, 0.0f));
        tmpPhysicsBody->setDynamic(false);
        tmpPhysicsBody->setCategoryBitmask(1);
        tmpPhysicsBody->setCollisionBitmask(1);
        tmpPhysicsBody->setContactTestBitmask(1);
        tmpPhysicsBody->setGravityEnable(false);

        Sprite* tmpSprite = Sprite::create();
        tmpSprite->setPosition(Vec2(x, y));
        tmpSprite->setAnchorPoint(Vec2::ZERO);
        tmpSprite->setContentSize(Size(width, height));
        tmpSprite->addComponent(tmpPhysicsBody);
        tmpSprite->setTag(kBarrierTag);
        tmpSprite->setName(Name::kBarrier);

        this->addChild(tmpSprite, kBarrierPriority);
        log("create barrer:%f", width);
    }
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

void GameScene::setViewPointByPlayer(Point position)
{
    //���鲻���ھ��˳�
    if (_player == nullptr)
        return;

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

    //log("playerPos.x=%f", playerPos.x);
    //log("map.x=%f", _mapinfo._map->getPosition().x);
    //log("this->getposition().x=%f", this->getPosition().x);
    x = std::min(x, mapSize.width - visibleSize.width / 2);
    y = std::min(y, mapSize.height - visibleSize.height / 2);

    //Ŀ���
    Vec2 destPos = Vec2(x, y);
    //��Ļ�е�
    Vec2 centerPos = Vec2(visibleSize.width / 2, visibleSize.height / 2);

    //��Ļ�е����Ҫ�ƶ���Ŀ���֮��ľ���
    Vec2 viewPos = centerPos - destPos;

    this->setPosition(viewPos);
}

//��ʱ���������
//bool GameScene::isColliding(Vec2 position)
//{
//    //ת������Ƭ����
//    cocos2d::Vec2 tilePos = this->tiledCoordFromPosition(position);
//
//    int tileGid = _mapinfo._obstacleLayer->getTileGIDAt(tilePos);
//    log("collidable id:%d", tileGid);
//    //��bug
//    if (tileGid != 0)
//    {
//        //Value prop = _mapinfo._map->getPropertiesForGID(tileGid);//���gid����
//        //Value propMap = prop.asValueMap().at("Collidable");
//        //if (prop.asString().compare("true") != 0)
//        //{
//            return true;
//        //}
//    }
//    return false;
//}