#pragma once
//#define NDEBUG
#include<cassert>
#include "cocos2d.h"
USING_NS_CC;
#include"ui/CocosGUI.h"
using namespace ui;
#include"Tool/SceneManager.h"
#include "Tool/MapInfo.h"
#include"Hero/HeroSprite.h"
#include"Hero/BeiyaHero.h"

class GameScene : public Scene
{
public:
    CREATE_FUNC(GameScene);

    virtual bool init();

    /********* @author:张靖凯************/
    //传入主角的坐标，放在控制器（控制角色）当中
    void setViewPointByPlayer(Point position);

    //判断是否碰撞障碍物（有bug！）(暂时不用)
    //传入的是openGL坐标(就是左下角为原点，2400*2400）向右为x向上为y
    //bool isColliding(Vec2 position);

    //转换成瓦片坐标（左上角为原点）
    Vec2 tiledCoordFromPosition(Vec2 position);

    //初始化地图
    void initMap();

    //创建障碍层
    void createBarrier();

    //添加宝箱
    void addRandomBox();
    void addBox();

    //schedule update
    void update(float dt);
    

private:
    //屏幕大小
    const Vec2 kVisibleSize = Director::getInstance()->getVisibleSize();




    /********* @author:张靖凯************/

    //地图信息（initMap()函数初始化了里面的变量）
    MapInfo _mapinfo;
    //主角
    Beiya* _player;
   
};

/********* @author:王琳************/
class poisonCircle :public Scene
{
public:

    //static Scene* scene();
    CREATE_FUNC(poisonCircle);

    
    virtual bool init();

    void updatepoisonCircle(float dt);

    cocos2d::Sprite* poisonCircleDown;
    cocos2d::Sprite* poisonCircleUp;
    cocos2d::Sprite* poisonCircleLeft;
    cocos2d::Sprite* poisonCircleRight;

   

    float poisonCircleMarch = 0.7f;
    float poisonCircleMax = 2400;

   // int poisonCircleDamage = 10;
   // float poisonCircleInterval = 3;

   // bool poisonCircleCanDamage = true;

};

