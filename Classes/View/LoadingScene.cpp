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

	//��ť������
	_login_button = Tools::ButtonCreate(Vec2(kVisibleSize.width / 2, kVisibleSize.height / 2 - 150)
		, "��ʼ��Ϸ", "ui/loadingButton.png", "ui/loadingButton_s.png", this);
	_login_button->addTouchEventListener([this](Ref*, ui::Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
				Tools::SwitchScene(this, Tools::SwitchSceneType::FadeOut);
		});

	//�˳���ť
	_exit_button = Tools::ButtonCreate(Vec2(kVisibleSize.width / 2, kVisibleSize.height / 2 - 250)
		, "������Ϸ", "ui/loadingButton.png", "ui/loadingButton_s.png", this);
	_exit_button->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
				Director::getInstance()->end();
		});

	return true;
}

//����

//Button* LoadingScene::SetButton(const Vec2&& pos, const std::string&& title, const std::string&& pic1, const std::string&& pic2)
//{
//	auto button = Button::create(pic1, pic2);
//	assert(button != NULL);
//	button->setPosition(pos);
//	button->setScale9Enabled(true);
//	button->setCapInsets(Rect(5, 5, 15, 15));
//	auto label = Label::createWithSystemFont(title, "΢���ź�", 40);
//	assert(label != NULL);
//	button->setTitleLabel(label);
//	button->setContentSize(Size(label->getContentSize().width + 120, label->getContentSize().height + 50));
//	this->addChild(button);
//	return button;
//}

bool LoadingScene::onTouchBegan(Touch*, Event*)
{
	//����Ҫ����true���loading��Ż���û����¼�����ǿ�
	return true;
}

