#pragma once

#include "cocos2d.h"
#include"ui/CocosGUI.h"

/**
* @brief ��Ϸ��ͣ��ָ�����
*/
class PauseScene :public cocos2d::Scene
{
public:

	CREATE_FUNC(PauseScene);

private:

	virtual bool init();

	PauseScene() : kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize())
		, _bg(NULL), _readme(NULL), _resume(NULL) {};

	///**
	//* @brief �����Ļ����ʧ
	//*/
	//virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);

	/*static void Capture(cocos2d::Scene* scene);

	static void AfterCapture(bool succeed, const std::string& outputFile);*/

private:

	const cocos2d::Size kVisibleSize;

	//������ͣ����
	cocos2d::Sprite* _bg;

	//��������ͣ�������Ļ����
	cocos2d::Label* _readme;

	//�ָ���ť
	cocos2d::ui::Button* _resume;

	/*static cocos2d::Scene* _scene;

	static std::string _outputfile;*/

};


