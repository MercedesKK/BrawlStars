#pragma once

#include "cocos2d.h"
#include"ui/CocosGUI.h"

/**
* @brief �˵������
*/
class MenuLayer :public cocos2d::Layer
{
public:

	CREATE_FUNC(MenuLayer);

private:

	virtual bool init();

	/**
	* @brief �˵����水ť������(����)
	*/
	void Set();

	MenuLayer() :_bg(NULL), _set(NULL), _ranking(NULL), _log(NULL)
		, kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize()) {};

	/**
	* @brief ����߽��������ʧ
	*/
	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);

private:

	const cocos2d::Size kVisibleSize;

	//���ò����
	cocos2d::ui::Scale9Sprite* _bg;

	//���ð�ť
	cocos2d::ui::Button* _set;

	//���а�ť
	cocos2d::ui::Button* _ranking;

	//��ս��־��ť
	cocos2d::ui::Button* _log;

	//��ͣ��ť
	cocos2d::ui::Button* _pause;

};

