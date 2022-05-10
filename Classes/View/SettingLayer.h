#pragma once

#include "cocos2d.h"
#include"ui/CocosGUI.h"

/**
* @brief ���ó���
*/
class SettingLayer :public cocos2d::Layer
{
public:

	CREATE_FUNC(SettingLayer);

private:

	virtual bool init();

	/**
	* @brief �˵�������(����)
	*/
	void Set();

	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);

	SettingLayer() :_bg(NULL), _soundmenu(NULL), _soundbar(NULL), _back(NULL)
		, kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize()) {};

	/**
	* @brief �����˵��Ļص�����
	*/
	void SoundmenuCloseCallback(cocos2d::Ref* pSender);

private:

	const cocos2d::Size kVisibleSize;

	//���û��汳��
	cocos2d::ui::Scale9Sprite* _bg;

	//���ò˵�
	cocos2d::Menu* _soundmenu;

	//�������ƻ���
	cocos2d::ui::Slider* _soundbar;

	//���ذ�ť
	cocos2d::ui::Button* _back;

};


