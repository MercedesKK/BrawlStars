#pragma once

#include "cocos2d.h"
#include"ui/CocosGUI.h"

/**
* @brief ��ʼ�ĵ�¼����,ʵ���ϼ̳���LayerȻ������main������
*/
class LoadingScene :public cocos2d::Layer
{
public:

	CREATE_FUNC(LoadingScene);

	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);

private:

	virtual bool init();

	//����

	//**
	//* @brief ���ð�ť��add������
	//* @param (Vec2&& pos)λ��
	//* @param ( std::string title)��ť����
	//* @param (std::string pic)ͼƬ·��
	//*/
	//cocos2d::ui::Button* SetButton(const cocos2d::Vec2&& pos, const std::string&& title, const std::string&& pic1, const std::string&& pic2);

	LoadingScene() :kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize())
		, _bg(NULL), _login_button(NULL), _exit_button(NULL) {};

private:

	const cocos2d::Size kVisibleSize;

	//��¼���汳��
	cocos2d::Sprite* _bg;

	//��¼��ť
	cocos2d::ui::Button* _login_button;

	//�˳���ť
	cocos2d::ui::Button* _exit_button;

};

