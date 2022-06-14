#include "LoadingScene.h"
USING_NS_CC;
using namespace ui;
#define NDEBUG
#include<cassert>
#include "Tool/SceneManager.h"
#include "Tool/Setting.h"
#include "Tool/Tools.h"
#include "Tool/Data.h"
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

	//δ��¼��Ҫ��½
	if (!Setting::getInstance()->isLogin())
	{
		//����id�ı���
		_text = Tools::TextCreate(kVisibleSize / 2, "�����������id(2�ַ���,δ֪��id��Ϣ���ڱ��豸�½��˺�)", 3, this);
		_text->addEventListener(CC_CALLBACK_2(LoadingScene::TextFieldEvent, this));
		_text->setColor(Color3B::BLACK);
		//�Ӹ��׿򣬿��������
		auto bg = Scale9Sprite::create("ui/button.png");
		assert(bg);
		bg->setCapInsets(Rect(5, 5, 15, 15));
		bg->setContentSize(Size(_text->getContentSize().width + 30, (_text->getContentSize().height + 15)));
		bg->setPosition(kVisibleSize / 2);
		this->addChild(bg);
		bg->setName("bg");

		//��¼��ť
		_login_button = Tools::ButtonCreate(Vec2(kVisibleSize.width / 2, kVisibleSize.height * 0.3f)
			, "��      ¼", "ui/loadingButton.png", "ui/loadingButton_s.png", this);
		//�����Ҫ��¼�Ļ�����дһ��������
		_login_button->addTouchEventListener([this](Ref*, ui::Widget::TouchEventType type)
			{
				if (type == Widget::TouchEventType::ENDED && _id != "")
				{
					Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
					auto distory = RemoveSelf::create();
					_login_button->runAction(distory);
					_text->runAction(distory->clone());
					this->removeChildByName("bg");

					//�о����·��release�汾Ҫ��һ�°���Ȼ��Ҫ��һ������
					PlistData::addDate(_id, "../Resources/Data/data" + _id + ".plist");

					MainScene::GetMainScene()->Load();
					Setting::getInstance()->SetLogin(true);
					LoadGame();
				}
			});
	}
	else
		LoadGame();

	CCLOG("LoadingScene finish");
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

void LoadingScene::TextFieldEvent(Ref* pSender, cocos2d::ui::TextField::EventType type)
{
	switch (type)
	{
	case cocos2d::ui::TextField::EventType::ATTACH_WITH_IME:
	{
		dynamic_cast<TextField*>(pSender)->setString("|");
		break;
	}
	case cocos2d::ui::TextField::EventType::DETACH_WITH_IME:
	{
		auto item = dynamic_cast<TextField*>(pSender);
		_id = item->getString().substr(1, item->getString().length() - 1);
		item->setString(_id);
		break;
	}
	default:
		break;
	}
}

bool LoadingScene::onTouchBegan(Touch*, Event*)
{
	//����Ҫ����true���loading��Ż���û����¼�����ǿ�
	return true;
}

