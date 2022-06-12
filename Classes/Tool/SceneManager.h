#pragma once
#define NDEBUG
#include<cassert>
#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "View/MainScene.h"
#include "View/GameScene.h"
#include "View/SettlementScene.h"
#include "View/PauseScene.h"

USING_NS_CC;

/**
* @brief �Զ���ĳ���ɸѡ��,��һ��������
*/
class SceneManager : public Ref
{
public:

    //����ö����
    enum class EnumSceneType
    {
        en_Min,
        en_MainScene,
        en_GameScene,
        en_SettlementScene,
        en_PauseScene,
        en_Max
    };

public:

    //��õ���
    static SceneManager* getInstance();

    /**
    * @brief �ı䳡��
    * @param ��EnumSceneType type�� ���ڵ�ö���࣬���ڱ�ǳ���
    */
    void changeScene(EnumSceneType type, int operate = 0);

    /**
    * @brief �ж��ǲ��ǵ�һ�����г���
    */
    bool isFirst() { return _first; }

    /**
    * @brief ���óɵ�һ�����г���
    */
    void SetFirst() { _first = true; }

private:

    SceneManager() :_first(true) {};

private:

    //��������������
    static SceneManager* _scene_manager;

    bool _first;

};