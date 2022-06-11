#include "SettingLayer.h"
USING_NS_CC;
using namespace ui;
//#define NDEBUG
#include<cassert>
#include "Tool/Setting.h"
#include"Tool/Tools.h"
#include "LoadingScene.h"
#include "MainScene.h"
#include"Tool/SceneManager.h"
#pragma execution_character_set("utf-8")  

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
	_back->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				Tools::SwitchScene(this, Tools::SwitchSceneType::Up);
			}
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
			if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
			{
				const int percent = dynamic_cast<Slider*>(ref)->getPercent();
				Setting::getInstance()->SoundPercentSet(percent);
			}
		});

	_soundmenu = Tools::MenuCreate(Vec2(-75, 15), "ui/sound.png", "ui/sound_close.png"
		, CC_CALLBACK_1(SettingLayer::SoundmenuCloseCallback, this), _soundbar);
	auto label1 = Tools::LabelCreateSystem(Vec2(_soundbar->getPosition().x, _soundbar->getPosition().y + 50)
		, "������", "΢���ź�", 30, this);
	label1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
	//����Ѿ����óɾ����˾͸ı�ͼ��
	if (!Setting::getInstance()->isSound())
		dynamic_cast<MenuItemToggle*>(_soundmenu->getChildByTag(0))->setSelectedIndex(1);

	/*------------------------------------------------------------------------------------------��Ч����*/
	_sound_effectBar = Tools::SliderCreate(Vec2(kVisibleSize.width / 2.f, kVisibleSize.height * 0.6f)
		, "ui/bar.png", "ui/bartexture.png", "ui/slider.png", this);
	_sound_effectBar->addEventListener([&](Ref* ref, Slider::EventType type)
		{
			if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
			{
				const int percent = dynamic_cast<Slider*>(ref)->getPercent();
				Setting::getInstance()->SoundEffectPercentSet(percent);
			}
		});

	_sound_effectMenu = Tools::MenuCreate(Vec2(-75, 15), "ui/sound.png", "ui/sound_close.png"
		, CC_CALLBACK_1(SettingLayer::SoundEffectmenuCloseCallback, this), _sound_effectBar);
	auto label2 = Tools::LabelCreateSystem(Vec2(_sound_effectBar->getPosition().x, _sound_effectBar->getPosition().y + 50)
		, "��Ч", "΢���ź�", 30, this);
	label2->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
	if (!Setting::getInstance()->isSoundEffect())
		dynamic_cast<MenuItemToggle*>(_sound_effectMenu->getChildByTag(0))->setSelectedIndex(1);

	/*------------------------------------------------------------------------------------------�˺Ų���*/
	_exit = Tools::ButtonCreate("�˳���¼", Vec2(kVisibleSize.width / 2.f, kVisibleSize.height * 0.4f), this);
	_exit->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				//��߻�Ҫɾ�������˺���Ϣ
				Setting::getInstance()->StopSound();
				Setting::getInstance()->SetLogin(false);
				SceneManager::getInstance()->changeScene(SceneManager::EnumSceneType::en_MainScene);
				auto distory = RemoveSelf::create();
				this->runAction(distory);
			}
		});

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
		Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
		if (item->getSelectedIndex() == 1)
			Setting::getInstance()->SoundSet(false);
		else
			Setting::getInstance()->SoundSet(true);
	}
}

void SettingLayer::SoundEffectmenuCloseCallback(cocos2d::Ref* pSender)
{
	const auto item = dynamic_cast<MenuItemToggle*>(pSender);
	if (item)
	{
		Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
		if (item->getSelectedIndex() == 1)
			Setting::getInstance()->SoundEffectSet(false);
		else
			Setting::getInstance()->SoundEffectSet(true);
	}
}

