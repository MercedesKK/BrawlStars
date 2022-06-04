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

	SettingLayer() : kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize())
		, _bg(NULL), _soundmenu(NULL), _soundbar(NULL), _back(NULL), _sound_effectMenu(NULL), _sound_effectBar(NULL) {};

	/**
	* @brief �����������˵��Ļص�����
	*/
	void SoundmenuCloseCallback(cocos2d::Ref* pSender);

	/**
	* @brief ��Ч�����˵��Ļص�����
	*/
	void SoundEffectmenuCloseCallback(cocos2d::Ref* pSender);

private:

	const cocos2d::Size kVisibleSize;

	//���û��汳��
	cocos2d::ui::Scale9Sprite* _bg;

	//�����������ò˵�
	cocos2d::Menu* _soundmenu;

	//�����������ƻ���
	cocos2d::ui::Slider* _soundbar;

	//���ذ�ť
	cocos2d::ui::Button* _back;

	//��Ч���ò˵�
	cocos2d::Menu* _sound_effectMenu;

	//��Ч���ƻ���
	cocos2d::ui::Slider* _sound_effectBar;

	//�˳���¼
	cocos2d::ui::Button* _exit;

};


