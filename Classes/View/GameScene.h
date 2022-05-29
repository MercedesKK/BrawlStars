#pragma once
//#define NDEBUG
#include<cassert>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Tool/SceneManager.h"
#include "Tool/MapInfo.h"
#include "Hero/HeroSprite.h"
#include "Hero/BeiyaHero.h"
#include "Tool/Timer.h"
#include "Participant/PlayerParticipant.hpp"
#include "Participant/ParticipantNode.hpp"


class GameScene : public cocos2d::Scene
{
public:
    CREATE_FUNC(GameScene);

    virtual bool init();

    /**
    * @brief �����������꣬�����ӽ�
    */
    void setViewPointByPlayer(cocos2d::Point position);


    /**
    * @brief ����ֵ
    */
    Participant* getHero() { return _player; } 
    cocos2d::Vector<cocos2d::Sprite*> getObstacle();
    cocos2d::Vector<cocos2d::Sprite*> getGrass();

    /**
    * @brief �жϴ��������Ƿ����ϰ����ݴԲ�
    * @param Ҫ��������
    */
    bool isBarrierExist(cocos2d::Point position);
    bool isGrassExist(cocos2d::Point position);


    /**
    * @brief ʹ��ɫ����ݴԱ�͸��
    * @����update������
    */
    void grassPlayerOpacity();


    /**
    * @brief ��ʼ����ͼ
    * @param chooseNum=1 ɳĮͼ
             chooseNum=2 ����ͼ    
             chooseNum=3 ������ͼ
    */
    void addMap(int chooseNum);
    //��ʼ��������10��λ��
    void initObjPosition();
    //���0-9��������
    std::vector<int> randTenNumberVec(int Num);

    /**
    * @��ʼ����ɫ�����ǣ�
    */
    void addHeroPlayer(); 


    /**
    * @brief �����ϰ���
    */
    void addBarrier();


    /**
    * @�����ݴ�
    */
    void addGrass();


    void addBox();

     /**
    * @brief �����ɫλ�� ������Ļ���ĵ�λ��
    * @param ��ɫ��λ��
    */
    cocos2d::Vec2 destPos(cocos2d::Point position);


    /**
    * @brief �������λ�ò������ϰ���
    */
    cocos2d::Vec2 randomPosWithoutBarrier();


    //��ʱ�ò���
    cocos2d::Vec2 tiledCoordFromPosition(cocos2d::Vec2 position);


    /********* @author:����************/
    //schedule update
    void update(float dt);

    void addPoisonCircle();

    void initializePoiosnPhysics(cocos2d::Sprite* poison);

   


private:

    //��ͼ��Ϣ��initMap()������ʼ��������ı�����
    MapInfo _mapinfo;
    //�ϰ�����
    cocos2d::Vector<cocos2d::Sprite*> _obstacle;
    //�ݴ�����
    cocos2d::Vector<cocos2d::Sprite*> _grass;
    //����
    Participant* _player;
    //���н�ɫ������
    std::vector<Participant*> _heroVec; 
    //10��λ��
    std::map<int, cocos2d::Vec2> _tenPosition;

    cocos2d::Sprite* poisonCircleDown;
    cocos2d::Sprite* poisonCircleUp;
    cocos2d::Sprite* poisonCircleLeft;
    cocos2d::Sprite* poisonCircleRight;
    cocos2d::Sprite* poisonDown;
    cocos2d::Sprite* poisonUp;
    cocos2d::Sprite* poisonLeft;
    cocos2d::Sprite* poisonRight;

    float poisonCircleMarch = 0.05f;
    float poisonCircleMax = 2400;
   

};



