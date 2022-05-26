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

    /**
    * @brief �����������꣬�����ӽ�
    */
    void setViewPointByPlayer(cocos2d::Point position);


    /**
    * @brief ����ֵ
    */
    Hero* getHero() { return _player; }
    //std::vector<HeroData> getHerodata() { return _herodataVec; }
    cocos2d::Vector<cocos2d::Sprite*> getObstacle();
    cocos2d::Vector<cocos2d::Sprite*> getGrass();


    /**
    * @brief ����ֵ
    */
    //std::vector<HeroData> setHerodata(std::vector<HeroData>& herodataVec) { _herodataVec = herodataVec; }


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
    * @��ʼ��AI��δʵ�֣�
    */
    //void addAIHeroPlayer(); 


    /**
    * @brief �����ϰ���
    */
    void addBarrier();


    /**
    * @�����ݴ�
    */
    void addGrass();


    /**
    * @��������
    */
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



    /********* @author:����************/
    //schedule update
    void update(float dt);
    



    //�ò���!!!
    cocos2d::Vec2 tiledCoordFromPosition(cocos2d::Vec2 position);
private:

    //��ͼ��Ϣ��initMap()������ʼ��������ı�����
    MapInfo _mapinfo;
    //�ϰ�����
    cocos2d::Vector<cocos2d::Sprite*> _obstacle;
    //�ݴ�����
    cocos2d::Vector<cocos2d::Sprite*> _grass;
    //����
    Hero* _player;
    //���н�ɫ������
    std::vector<Hero*> _heroVec; 
    //10��λ��
    std::map<int, cocos2d::Vec2> _tenPosition;
};
