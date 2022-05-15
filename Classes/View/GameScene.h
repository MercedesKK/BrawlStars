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

    //�ж��Ƿ���ײ�ϰ����bug����(��ʱ����)
    //�������openGL����(�������½�Ϊԭ�㣬2400*2400������Ϊx����Ϊy
    //bool isColliding(Vec2 position);


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

    ////ʱ���UI
    //void setTimeUI(MyTimer& timer);
    /********* @author:����************/
    
    void update(float dt);

private:
    //��Ļ��С
    const cocos2d::Vec2 kVisibleSize = cocos2d::Director::getInstance()->getVisibleSize();

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


