#include "SettingLayer.h"
USING_NS_CC;
using namespace ui;
//#define NDEBUG
#include<cassert>
#include "Tool/Setting.h"
#include"Tool/Tools.h"

bool SettingLayer::init()
{
	if (!Layer::init())
		return false;

	//�������ɵ���¼�
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(SettingLayer::onTouchBegan, this);
	Tools::LayerSwallow(listener, this);

	//����
	_bg = Tools::SetBg(this);

	//���ò˵�
	Set();

	//���ذ�ť
	_back = Tools::ButtonCreate(Vec2(100, kVisibleSize.height - 100), "ui/back.png", this);
	_back->addTouchEventListener([this](Ref*, Widget::TouchEventType)
		{
			auto distory = RemoveSelf::create();
			auto move = MoveTo::create(0.5f, Vec2(0, kVisibleSize.height));
			this->runAction(Sequence::createWithTwoActions(move, distory));
           //�������ϻ��µ�Ч��
		});

	return true;
}

void SettingLayer::Set()
{

	/*------------------------------------------------------------------------------------------��������*/

	_soundbar = Tools::SliderCreate(Vec2(kVisibleSize.width / 2.f, kVisibleSize.height * 0.8f)
		, "ui/bar.png", "ui/bartexture.png", "ui/slider.png", this);
	_soundbar->addEventListener([&](Ref* ref, Slider::EventType type)
		{
			//�����¼�
			if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
			{
				const int percent = dynamic_cast<Slider*>(ref)->getPercent();
				Setting::getInstance()->SoundPercentSet(percent);
			}
		});

	_soundmenu = Tools::MenuCreate(Vec2(-75, 15), "ui/sound.png", "ui/sound_close.png"
		, CC_CALLBACK_1(SettingLayer::SoundmenuCloseCallback, this), _soundbar);
}

bool SettingLayer::onTouchBegan(cocos2d::Touch*, cocos2d::Event*)
{
	return true;
}

void SettingLayer::SoundmenuCloseCallback(cocos2d::Ref* pSender)
{
	const auto item = dynamic_cast<MenuItemToggle*>(pSender);
	if (item)
	{
		if (item->getSelectedIndex() == 0)
			Setting::getInstance()->SoundSet(false);
		else
			Setting::getInstance()->SoundSet(true);
	}
}
