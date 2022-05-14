#pragma once
#include "cocos2d.h"
#include "Const/Const.h"

class MapInfo
{
public:
    //��ͼ
    cocos2d::TMXTiledMap* _map;
    //��ײ��(��bug)
    cocos2d::TMXLayer* _obstacleLayer;
    //��ͼ��������
    cocos2d::Size _mapTiledNum;
    //�������Ӵ�С����bug������!��
    cocos2d::Size _tiledSize;
    //��ײ��Ƭ�����½ǵ���Ƭ����,�������ײ��������Ϊtrue��//����ʱ�ò������������ܣ�
    TileVector _collisionBoard = TileVector(_mapTiledNum.width, std::vector<bool>(_mapTiledNum.height, false));
public:
    void setCollisionBoard();
    //�������һ��λ��
    static cocos2d::Vec2 randomPos();
};