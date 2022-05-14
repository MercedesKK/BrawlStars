#include "RoomLayer.h"
USING_NS_CC;
using namespace ui;
//#define NDEBUG
#include<cassert>
#include "Tool/SceneManager.h"
#include"Tool/Tools.h"
#include"Tool/Setting.h"
#pragma execution_character_set("utf-8")  

static constexpr int kEnemyTag = 0;
static constexpr int kOurTag = 1;

bool RoomLayer::init()
{
	if (!Layer::init())
		return false;

	//�������ɵ���¼�
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(RoomLayer::onTouchBegan, this);
	Tools::LayerSwallow(listener, this);

	//�㱳��
	_bg = Tools::SetBg(this);

	//��ʼ��Ϸ��ť
	_start = Tools::ButtonCreate("��ʼ��ս", Vec2(kVisibleSize.width - 130, 75), this);
	_start->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				SceneManager::getInstance()->changeScene(SceneManager::EnumSceneType::en_GameScene);
			}
		});

	//���ذ�ť
	_back = Tools::ButtonCreate(Vec2(77, kVisibleSize.height - 40), "ui/back.png", this);
	_back->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				Tools::SwitchScene(this, Tools::SwitchSceneType::Up);
			}
		});

	//6�������Ա��
	MemberCreate();

	//VS����
	_vs = Tools::LabelCreateSystem(kVisibleSize / 2, "����ս", "΢���ź�", 70, this);

	//�Զ���ȫ�����˰�ť
	_robots = Tools::ButtonCreate("��ȫ������", Vec2(125, 100), this);
	_robots->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			//�����ҷ��͵з������˸���
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				/*while (_enemy.setRobot(true));
				while (_our.setRobot(true));*/
				while (_member.setRobot(true));
				//����_figuresʵ�ַ�ת(ʹ�û��ڷ�Χ��Forѭ��)
				for (auto item : _figures)
				{
					if (item->getSelectedIndex() == 1);
					else if(item->getSelectedIndex() == 0)
						item->setSelectedIndex(1);
				}
			}
		});

	return true;
}

bool RoomLayer::onTouchBegan(cocos2d::Touch*, cocos2d::Event*)
{
	return true;
}

void RoomLayer::MemberCreate()
{
	//��ȡmain�����ľ���
	//�Ȱ��ҷ�����������
	PlusMemberCreate();
}

void RoomLayer::PlusMemberCreate()
{
	for (int i = 1; i <= 9; ++i)
	{
		auto box1 = MenuItemImage::create("ui/box.png", "ui/box.png");
		auto box2 = MenuItemImage::create("ui/box_robot.png", "ui/box_robot.png");
		assert(box1 != NULL);
		assert(box2 != NULL);
		//�����������Ļ����callback����Ҫ��һ��
		auto box0 = MenuItemToggle::createWithCallback(CC_CALLBACK_1(RoomLayer::menuCloseCallback, this), box1, box2, NULL);
		_figures.pushBack(box0);
		auto box = Menu::create(box0, NULL);
		this->addChild(box);

		if (i <= 5)
		{
			//����tag������֮�����tag�����ĸ�Menber��Ա������
			//box0->setTag(kEnemyTag);
			box->setPosition(Vec2(kVisibleSize.width / 2 + (i - 3) * 150, kVisibleSize.height / 2 + 200));
		}
		else
		{
			//����tag������֮�����tag�����ĸ�Menber��Ա������
			//box0->setTag(kOurTag);
			box->setPosition(Vec2(kVisibleSize.width / 2 + (i - 7) * 150, kVisibleSize.height / 2 - 200));
		}
		box->setContentSize(Size(50, 125));
	    
	}
}

void RoomLayer::menuCloseCallback(Ref* pSender)
{
	//������Ҫ�����˻���Ҫ��һ����ѡ��ѡ��֮�󴫸����Ȼ����һ����ҵĽ�ɫͼ���ԭ�������˵�ͼ���ס�ɣ�����֮֮����˵
	//������Լ�һ��ѡ��ť�ĵڶ��ε�������������ң�
	auto const item = dynamic_cast<MenuItemToggle*>(pSender);
	if (item)
	{
		if (item->getSelectedIndex()==1)
		{
			/*if (item->getTag() == kOurTag)
				_our.setRobot(true);
			else if (item->getTag() == kEnemyTag)
				_enemy.setRobot(true);*/
			_member.setRobot(true);
		}
		else
		{
			/*if (item->getTag() == kOurTag)
				_our.setRobot(false);
			else if (item->getTag() == kEnemyTag)
				_enemy.setRobot(false);*/
			_member.setRobot(false);
		}
	}
}


		
