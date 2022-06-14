#include "MainScene.h"
USING_NS_CC;
using namespace ui;
#define NDEBUG
#include<cassert>
#include "LoadingScene.h"
#include "RoomLayer.h"
#include "SettingLayer.h"
#include "Tool/Setting.h"
#include "Tool/SceneManager.h"
#include "Tool/Tools.h"
#include "FigureLayer.h"
#include "InforLayer.h"
#include "MenuLayer.h"
#include "FriendLayer.h"
#include "Tool/Data.h"
#include "Net/Client.h"
#include "Const/Const.h"
#include"Factory/HeroFactory.h"

#pragma execution_character_set("utf-8")  

MainScene* MainScene::_that = NULL;

void MainScene::SetInfo(const std::string& filename)
{
	_info_button->removeAllChildren();
	auto item = Sprite::create(filename);
	assert(item);
	_info_button->setName(filename);
	_info_button->addChild(item);
	item->setPosition(_info_button->getContentSize() / 2);
}

std::string MainScene::GetInfo()
{
	return _info_button->getName();
}

void MainScene::Load()
{
	//��������ʾ������
	_figure = Tools::ButtonCreateN(kVisibleSize / 2, PlistData::getDataByType(PlistData::DataType::Figure), this);
	_figure->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				_changeFigure = FigureLayer::create();
				assert(_changeFigure != 0);
				this->addChild(_changeFigure, 100);
				Tools::SwitchScene(_changeFigure, Tools::SwitchSceneType::Down);
			}
		});

	//������Ϣ��ť
	_info_button = Tools::ButtonCreate(Vec2(77, kVisibleSize.height - 40), PlistData::getDataByType(PlistData::DataType::Profile), this);
	_info_button->setName("ui/info1.png");
	_info_button->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				_info = InforLayer::create();
				assert(_info);
				this->addChild(_info);
				Tools::SwitchScene(_info, Tools::SwitchSceneType::Down);
			}
		});

	auto heroVec = HeroFactory::getInstance()->getClassIDVec();
	auto figurename = PlistData::getDataByType(PlistData::DataType::Figure);
	for (auto name : heroVec)
	{
		if (HeroFactory::getInstance()->createWithClassID(name)->getHeroPicture() == figurename)
		{
			if (herodataVec.size() >= 1)
				herodataVec.at(0) = HeroData(name + " false", PlistData::getDataByType(PlistData::DataType::ID));
			else
				herodataVec.push_back(HeroData(name + " false", PlistData::getDataByType(PlistData::DataType::ID)));
		}
	}
}

bool MainScene::init()
{
	if (!Scene::init())
		return false;

	_that = this;
	/*******************************�����************************************/

	//�������̼�����
	_gmlistenerKeyBoard = EventListenerKeyboard::create();
	//�󶨼����¼�
	_gmlistenerKeyBoard->onKeyPressed = CC_CALLBACK_2(MainScene::onPressKey, this);
	_gmlistenerKeyBoard->onKeyReleased = CC_CALLBACK_2(MainScene::onReleaseKey, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_gmlistenerKeyBoard, this);

	//�����
	_chatBox = ChatBox::create();
	_chatBox->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	this->addChild(_chatBox);
	_chatBox->setGlobalZOrder(kFightUI);
	_chatBox->setVisible(false);
	/*******************************�����************************************/

	//��ʼ��Tools
	Tools::set();

	//���ñ���
	_bg = Tools::SetBg("ui/MainBg.png", this);

	//����loading����
	if (!Setting::getInstance()->isLogin())
	{
		_loading = LoadingScene::create();
		assert(_loading != NULL);
		this->addChild(_loading, 100);
	}
	else
		Load();

	//�˵���ť
	_menu_button = Tools::ButtonCreate(Vec2(275, kVisibleSize.height - 40), "ui/menu.png", this);
	_menu_button->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				_menu = MenuLayer::create();
				assert(_menu);
				this->addChild(_menu);
				Tools::SwitchScene(_menu, Tools::SwitchSceneType::LeftToRight);
			}
		});

	//�����䰴ť
	_play_button = Tools::ButtonCreate("��   ս", Vec2(kVisibleSize.width - 200, 75), this);
	_play_button->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				_room = RoomLayer::create();
				assert(_room);
				this->addChild(_room, 100);
				Tools::SwitchScene(_room, Tools::SwitchSceneType::Down);
			}
		});

	//���ذ�ť
	_back = Tools::ButtonCreate(Vec2(175, kVisibleSize.height - 40), "ui/back.png", this);
	_back->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			//�������Ļ�����ͽ���������ᴴ��һ���㣬��������
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				Setting::getInstance()->StopSound();
				_loading = LoadingScene::create();
				assert(_loading != NULL);
				this->addChild(_loading, 100);
				Tools::SwitchScene(_loading, Tools::SwitchSceneType::FadeIn);
			}
		});

	//���Ѱ�ť
	_friends = Tools::ButtonCreate(Vec2(375, kVisibleSize.height - 40), "ui/friend.png", this);
	_friends->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				_friend = FriendLayer::create();
				assert(_friend);
				this->addChild(_friend);
				Tools::SwitchScene(_friend, Tools::SwitchSceneType::Down);
			}
		});

	//��Ϣ��ť
	_messages = Tools::ButtonCreate(Vec2(75, 40), "ui/message.png", this);
	_messages->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				_countButton++;

				if (_countButton % 2 == 1)
				{
					_chatBox->setVisible(true);
				}
				else
				{
					_chatBox->setVisible(false);
				}
				//����ϵͳ�������һ������Ĳ������
			}
		});

	this->scheduleUpdate();

	CCLOG("main finish");
	return true;
}

void MainScene::updateChatBoxPosition()
{
	{
		auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

		//�����
		_chatBox->setPosition(190,80);
	}
}

void MainScene::update(float dt)
{
	updateChatBoxPosition();
}

void MainScene::SetFigure(const std::string& filename)
{
	if (filename != _figure->getNormalFile().file)
	{
		this->scheduleOnce([this, filename](float dlt)
			{
				_figure->removeFromParent();
				_figure = Tools::ButtonCreateN(kVisibleSize / 2, filename, this);
				_figure->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
					{
						if (type == Widget::TouchEventType::ENDED)
						{
							_changeFigure = FigureLayer::create();
							assert(_changeFigure != 0);
							this->addChild(_changeFigure);
							Tools::SwitchScene(_changeFigure, Tools::SwitchSceneType::Down);
						}
					});
			}, 0.5f, "delaytime");
	}
}

std::string MainScene::GetFigure() const
{
	return _figure->getNormalFile().file;
}

bool MainScene::onPressKey(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (_countButton % 2 == 1)
	{
		if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
		{
			_chatBox->enterToUpdateMessage();
		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE)
		{
			_chatBox->backspaceTodateMessage();
		}
		else
		{
			_chatBox->updateMessage(ChatBox::switchKeycodeToChar(keyCode));
		}
	}

	return true;
}

bool MainScene::onReleaseKey(EventKeyboard::KeyCode keyCode, Event* event)
{
	return false;
}

int MainScene::_countButton = 0;