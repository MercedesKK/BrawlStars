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

    Beiya* getBeiya() { return _player; };


    //ת������Ƭ���꣨���Ͻ�Ϊԭ�㣩
    cocos2d::Vec2 tiledCoordFromPosition(cocos2d::Vec2 position);


    //�����ϰ���/�ݴ�
    cocos2d::Vector<cocos2d::Sprite*> getObstacle();
    cocos2d::Vector<cocos2d::Sprite*> getGrass();


    //�ж��Ƿ����ϰ���/�ݴ�,���򷵻�true
    bool isBarrierExist(cocos2d::Point position);
    bool isGrassExist(cocos2d::Point position);

    void grassPlayerOpacity();

    //��ʼ����ͼ
    void addMap();


    //��ʼ����ɫ
    void addHeroPlayer();


    //void addAIHeroPlayer(); 


    //�����ϰ���
    void addBarrier();


    //�����ݴ�
    void addGrass();

    void inTimerViewScreen();

    //��Ļ���ĵ�λ��
    Vec2 destPos(Point position);

    /********* @author:����************/
    //schedule update
    void update(float dt);
    

private:
    //��Ļ��С
    const Vec2 kVisibleSize = Director::getInstance()->getVisibleSize();


    /********* @author:�ž���************/

    //��ͼ��Ϣ��initMap()������ʼ��������ı�����
    MapInfo _mapinfo;
    //�ϰ�����
    cocos2d::Vector<cocos2d::Sprite*> _obstacle;
    //�ݴ�����
    cocos2d::Vector<cocos2d::Sprite*> _grass;
    //����
    Beiya* _player;
   
};

///********* @author:����************/
//class poisonCircle :public Scene
//{
//public:
//
//    //static Scene* scene();
//    CREATE_FUNC(poisonCircle);
//
//
//
//    virtual bool init();
//
//    void updatepoisonCircle(float dt);
//
//    cocos2d::Sprite* poisonCircleDown;
//    cocos2d::Sprite* poisonCircleUp;
//    cocos2d::Sprite* poisonCircleLeft;
//    cocos2d::Sprite* poisonCircleRight;
//    float poisonCircleMarch = 0.7f;
//    float poisonCircleMax = 2400;
//
//    // int poisonCircleDamage = 10;
//    // float poisonCircleInterval = 3;
//
//    // bool poisonCircleCanDamage = true;
//
//};
