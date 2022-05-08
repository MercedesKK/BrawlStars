#include"cocos2d.h"
USING_NS_CC;
#include "View\GameScene.h"

void GameScene::initMap()
{
    //初始化各个变量！！！！！！！！
    _mapinfo._map = TMXTiledMap::create("map/mapNo1.tmx");
    _mapinfo._map->setAnchorPoint(Vec2::ZERO);
    _mapinfo._map->setPosition(Vec2::ZERO);
    this->addChild(_mapinfo._map);

    //碰撞层
    //_mapinfo._obstacleLayer = _map->getLayer("meta");

    //地图方块数量
    _mapinfo._mapTiledNum = _mapinfo._map->getMapSize();
    //单个格子大小(直接初始化好）（有bug！！！）
    _mapinfo._tiledSize = _mapinfo._map->getTileSize() + Size(_mapinfo._map->getTileSize().width / 4, _mapinfo._map->getTileSize().height / 4);
    //设置_collisionBoard
    //_mapinfo.setCollisionBoard();
    
    //初始化结束


}





Vec2 GameScene::tiledCoordFromPosition(Vec2 position)
{
    int mpx = _mapinfo._tiledSize.width * _mapinfo._mapTiledNum.width;
    int mpy = _mapinfo._tiledSize.height * _mapinfo._mapTiledNum.height;
    //opengl坐标
    Vec2 posInMap = Vec2(position.x, position.y);
    //UI像素坐标
    Vec2 posInMapUI = Vec2(position.x, mpy - position.y);

    //转换成瓦片坐标
    int x = posInMapUI.x / _mapinfo._tiledSize.width;
    int y = posInMapUI.y / _mapinfo._tiledSize.height;

    return Vec2(x, y);
}

bool GameScene::isColliding(Vec2 position)
{
    //转化成瓦片坐标
    cocos2d::Vec2 tilePos = this->tiledCoordFromPosition(position);

    int tileGid = _mapinfo._obstacleLayer->getTileGIDAt(tilePos);
    //log("playerPos.x=%f", tilePos.x);
    //有bug
    if (tileGid != 0)
    {
        Value prop = _mapinfo._map->getPropertiesForGID(tileGid);//获得gid属性
        Value propMap = prop.asValueMap().at("Collidable");
        if (prop.asString().compare("true") != 0)
            return true;
    }
    return false;
}

void GameScene::setViewPointByPlayer(Point position)
{
    //精灵不存在就退出
    if (_player == nullptr)
        return;

    //屏幕大小
    Size visibleSize = Director::getInstance()->getVisibleSize();

    //地图大小
    Size mapSize = Size(_mapinfo._mapTiledNum.width * _mapinfo._tiledSize.width, _mapinfo._mapTiledNum.height * _mapinfo._tiledSize.height);

    //主角坐标 
    Point playerPos = position;

    //如果主角坐标小于屏幕一半，则取屏幕中点坐标
    //算法
    float x = std::max(playerPos.x, visibleSize.width / 2);
    float y = std::max(playerPos.y, visibleSize.height / 2);

    log("playerPos.x=%f", playerPos.x);
    log("map.x=%f", _mapinfo._map->getPosition().x);
    log("this->getposition().x=%f", this->getPosition().x);
    x = std::min(x, mapSize.width - visibleSize.width / 2);
    y = std::min(y, mapSize.height - visibleSize.height / 2);

    //目标点
    Vec2 destPos = Vec2(x, y);
    //屏幕中点
    Vec2 centerPos = Vec2(visibleSize.width / 2, visibleSize.height / 2);

    //屏幕中点和所要移动的目标点之间的距离
    Vec2 viewPos = centerPos - destPos;

    this->setPosition(viewPos);
}
