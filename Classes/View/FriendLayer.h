#pragma once

#include "cocos2d.h"
#include"ui/CocosGUI.h"

/**
* @brief ������ĺ��Ѳ�
*/
class FriendLayer : public cocos2d::Layer
{
public:

    CREATE_FUNC(FriendLayer);

private:

    virtual bool init();

    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*) { return true; }

    FriendLayer() :kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize())
        , _bg(NULL), _back(NULL), _text(NULL) {};

private:

    const cocos2d::Size kVisibleSize;

    //����
    cocos2d::Sprite* _bg;

    //���ذ�ť
    cocos2d::ui::Button* _back;

    //��Ӻ��Ѱ�ť
    cocos2d::ui::Button* _addFriend;

    //�ı���
    cocos2d::ui::TextField* _text;

};

