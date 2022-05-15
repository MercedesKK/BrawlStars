#pragma once
//#define NDEBUG
#include<cassert>
#include "cocos2d.h"
#include"ui/CocosGUI.h"
#include"Tool/SceneManager.h"
#include "Tool/MapInfo.h"
#include"Hero/HeroSprite.h"
#include"Hero/BeiyaHero.h"
#include"Tool/Timer.h"

class GameScene : public cocos2d::Scene
{
public:
    CREATE_FUNC(GameScene);

    virtual bool init();

    /********* @author:�ž���************/
    //�������ǵ����꣬���ڿ����������ƽ�ɫ������
    void setViewPointByPlayer(cocos2d::Point position);


    //�ж��Ƿ���ײ�ϰ����bug����(��ʱ����)
    //�������openGL����(�������½�Ϊԭ�㣬2400*2400������Ϊx����Ϊy
    //bool isColliding(Vec2 position);

    //ת������Ƭ���꣨���Ͻ�Ϊԭ�㣩
    cocos2d::Vec2 tiledCoordFromPosition(cocos2d::Vec2 position);

    //��ʼ����ͼ
    void initMap();

    //�����ϰ���
    void createBarrier();


    //schedule update
    void update(float dt);
    

private:
    //��Ļ��С
    const Vec2 kVisibleSize = Director::getInstance()->getVisibleSize();




    /********* @author:�ž���************/

    //��ͼ��Ϣ��initMap()������ʼ��������ı�����
    MapInfo _mapinfo;
    //����
    Beiya* _player;
   
};

/********* @author:����************/
class poisonCircle :public Scene
{
public:

    //static Scene* scene();
    CREATE_FUNC(poisonCircle);


    ////��ӱ���
    //void addRandomBox();
    //void addBox();


    /********* @author:����************/
    
    void update(float dt);

    float poisonCircleMarch = 0.7f;
    float poisonCircleMax = 2400;

   // int poisonCircleDamage = 10;
   // float poisonCircleInterval = 3;

   // bool poisonCircleCanDamage = true;

};

