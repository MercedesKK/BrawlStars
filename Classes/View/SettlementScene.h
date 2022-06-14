#pragma once

#include "cocos2d.h"
#include"ui/CocosGUI.h"

/**
 * @brief ���㳡��
 */
class SettlementScene : public cocos2d::Scene
{
public:

    CREATE_FUNC(SettlementScene);

private:

    virtual bool init();

    SettlementScene() :kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize())
        , _continue(NULL), _bg(NULL), _figure(NULL), _cups(NULL), _money(NULL) {};

    /**
    * @brief ����Ϸ�������ж�������˳�򣬷��佱��
    */
    void Win();

    ///**
    //* @brief ����Ϸ�������ж����ҷ��͵з���heroȻ�����Ƭ������,Ȼ���Ӧ��ս��ҲҪ��,�ڵ���+��ǩ��
    //*/
    //void ShowRecord();

private:
     
    const cocos2d::Size kVisibleSize;
    
    //������ť
    cocos2d::ui::Button* _continue;

    //����
    cocos2d::Sprite* _bg;

    //���Ӣ��չʾ
    cocos2d::Sprite* _figure;

    //��ý�����
    cocos2d::Label* _cups;

    //��ý����
    cocos2d::Label* _money;

};