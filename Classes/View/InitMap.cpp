/**
* @author �ž���
* @brief ��ʼ����ͼ
*/
#include"cocos2d.h"
#include "View\GameScene.h"
#include "Const/Const.h"
using namespace std;
USING_NS_CC;

void GameScene::addMap()
{
    //��ʼ��������������������������
    const int mapChooseNum = random(1, 3);
    string mapChooseStr;
    if (mapChooseNum == 1)
        mapChooseStr = Path::map1;
    else if (mapChooseNum == 2)
        mapChooseStr = Path::map2;
    else if (mapChooseNum == 3)
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

    //�ݴԲ�������Ŷ~~~~
    //_mapinfo._obstacleLayer = _mapinfo._map->getLayer("4");
    //_mapinfo._obstacleLayer->setGlobalZOrder(kTMXlayer);
    // 
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
    log("destPos.x=%f", destPosition.x);
    this->setPosition(viewPos);
}
