#include "LoadingScene.h"
USING_NS_CC;
using namespace ui;
//#define NDEBUG
#include<cassert>
#include "Tool/SceneManager.h"
#include "Tool/Setting.h"
#include "Tool/Tools.h"
#pragma execution_character_set("utf-8")  

bool LoadingScene::init()
{
	if (!Layer::init())
		return false;

	//������ʼ
	Setting::getInstance()->GoSound("audio/main.mp3");
	
	//�������ɵ���¼�(��֪��Ϊʲôǰ����ӵ���װ��ڶ���ȺŻᱨ��)
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(LoadingScene::onTouchBegan, this);
	Tools::LayerSwallow(listener, this);

	//����������
	_bg = Tools::SetBg("ui/loadingBg.jpg", this);

	if (true)//���û�е�¼��Ϣ�Ļ�,��Ҫ������
	{
		//��¼��ť
		_login_button = Tools::ButtonCreate(Vec2(kVisibleSize.width / 2, kVisibleSize.height * 0.3f)
			, "��      ¼", "ui/loadingButton.png", "ui/loadingButton_s.png", this);
		//�����Ҫ��¼�Ļ�����дһ��������
		_login_button->addTouchEventListener([this](Ref*, ui::Widget::TouchEventType type)
			{
				if (type == Widget::TouchEventType::ENDED)
				{
					Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
					auto distory = RemoveSelf::create();
					_login_button->runAction(distory);
					LoadGame();
				}
			});
	}

	return true;
}

void LoadingScene::LoadGame()
{
	/*-----------------------------------------------------------------------------------��ʼ��Ϸ��ť*/
	_start_button = Tools::ButtonCreate(Vec2(kVisibleSize.width / 2, kVisibleSize.height / 2 - 150)
		, "��ʼ��Ϸ", "ui/loadingButton.png", "ui/loadingButton_s.png", this);
	_start_button->addTouchEventListener([this](Ref*, ui::Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				Tools::SwitchScene(this, Tools::SwitchSceneType::FadeOut);
			}
		});

	/*-----------------------------------------------------------------------------------�˳���ť*/
	_exit_button = Tools::ButtonCreate(Vec2(kVisibleSize.width / 2, kVisibleSize.height / 2 - 250)
		, "������Ϸ", "ui/loadingButton.png", "ui/loadingButton_s.png", this);
	_exit_button->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				Director::getInstance()->end();
			}
		});

}

bool LoadingScene::onTouchBegan(Touch*, Event*)
{
	//����Ҫ����true���loading��Ż���û����¼�����ǿ�
	return true;
}

