#include"cocos2d.h"
USING_NS_CC;
#include "View\GameScene.h"

void GameScene::initMap()
{
    //��ʼ��������������������������
    _mapinfo._map = TMXTiledMap::create("map/mapNo1.tmx");
    _mapinfo._map->setAnchorPoint(Vec2::ZERO);
    _mapinfo._map->setPosition(Vec2::ZERO);
    this->addChild(_mapinfo._map);

    //��ײ��
    //_mapinfo._obstacleLayer = _map->getLayer("meta");

    //��ͼ��������
    _mapinfo._mapTiledNum = _mapinfo._map->getMapSize();
    //�������Ӵ�С(ֱ�ӳ�ʼ���ã�����bug��������
    _mapinfo._tiledSize = _mapinfo._map->getTileSize() + Size(_mapinfo._map->getTileSize().width / 4, _mapinfo._map->getTileSize().height / 4);
    //����_collisionBoard
    //_mapinfo.setCollisionBoard();
    
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

bool GameScene::isColliding(Vec2 position)
{
    //ת������Ƭ����
    cocos2d::Vec2 tilePos = this->tiledCoordFromPosition(position);

    int tileGid = _mapinfo._obstacleLayer->getTileGIDAt(tilePos);
    //log("playerPos.x=%f", tilePos.x);
    //��bug
    if (tileGid != 0)
    {
        Value prop = _mapinfo._map->getPropertiesForGID(tileGid);//���gid����
        Value propMap = prop.asValueMap().at("Collidable");
        if (prop.asString().compare("true") != 0)
            return true;
    }
    return false;
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

    log("playerPos.x=%f", playerPos.x);
    log("map.x=%f", _mapinfo._map->getPosition().x);
    log("this->getposition().x=%f", this->getPosition().x);
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
