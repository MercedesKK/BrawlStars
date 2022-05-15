#include "FriendLayer.h"
USING_NS_CC;
using namespace ui;
//#define NDEBUG
#include<cassert>
#include "Tool/Setting.h"
#include"Tool/Tools.h"
//#include "LoadingScene.h"
//#include "MainScene.h"
//#include"Tool/SceneManager.h"
#pragma execution_character_set("utf-8")  

bool FriendLayer::init()
{
	if (!Layer::init())
		return false;

	//�������ɵ���¼�
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(FriendLayer::onTouchBegan, this);
	Tools::LayerSwallow(listener, this);

	//����
	_bg = Tools::SetBg(this);

	//���ذ�ť
	_back = Tools::ButtonCreate(Vec2(100, kVisibleSize.height - 100), "ui/back.png", this);
	_back->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				Tools::SwitchScene(this, Tools::SwitchSceneType::Up);
			}
		});

	//��Ӻ���
	_addFriend = Tools::ButtonCreate("��Ӻ���", Vec2(kVisibleSize.width / 2, kVisibleSize.height * 0.2f), this);
	_addFriend->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				//���ı��������_text
			}
		});

	//���Ӧ���д����϶�ȡ�������ݣ�Ȼ�������б�emmmȻ�����֧�ֲ鿴����һЩ���ݺ�˽�ģ�

	return true;
}
