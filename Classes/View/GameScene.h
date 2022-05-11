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

    /********* @author:�ž���************/
    //�������ǵ����꣬���ڿ����������ƽ�ɫ������
    void setViewPointByPlayer(Point position);

    //�ж��Ƿ���ײ�ϰ����bug����(��ʱ����)
    //�������openGL����(�������½�Ϊԭ�㣬2400*2400������Ϊx����Ϊy
    //bool isColliding(Vec2 position);

    //ת������Ƭ���꣨���Ͻ�Ϊԭ�㣩
    Vec2 tiledCoordFromPosition(Vec2 position);

    //��ʼ����ͼ
    void addMap();

    //��ʼ����ɫ
    void addHeroPlayer();

    //�����ϰ���
    void addBarrier();

    //��ӱ���
    void addRandomBox();
    void addBox();


    /********* @author:����************/
    
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


