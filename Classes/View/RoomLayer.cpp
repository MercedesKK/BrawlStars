#include "RoomLayer.h"
USING_NS_CC;
using namespace ui;
#define NDEBUG
#include<cassert>
#include "Tool/SceneManager.h"
#include"Tool/Tools.h"
#include"Tool/Setting.h"
#include"Tool/Data.h"
#include"FigureLayer.h"
#include"Factory/HeroFactory.h"
#include"Const/Const.h"
#include<time.h>
#include <stdlib.h> 
#pragma execution_character_set("utf-8")  

//���Ӣ����Ϣ������Ϸ
extern std::vector<HeroData> herodataVec;

static constexpr int kEnemyTag = 0;
static constexpr int kOurTag = 1;
RoomLayer* RoomLayer::_that = NULL;

bool RoomLayer::init()
{
	if (!Layer::init())
		return false;

	_that = this;

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
				SetHero();
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

	//10�������Ա��
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
	//�Ȱѷ���������
	_self = Tools::ButtonCreateN(Vec2(kVisibleSize.width / 2 + (-2) * 150, kVisibleSize.height / 2 - 200)
		, PlistData::getDataByType(PlistData::DataType::Figure), this);
	_self->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
				auto changeFigure = FigureLayer::create();
				assert(changeFigure != 0);
				this->addChild(changeFigure);
				Tools::SwitchScene(changeFigure, Tools::SwitchSceneType::Down);
				_humandata.push_back(HumanData(PlistData::getDataByType(PlistData::DataType::Figure)));
			}
		});
	_humandata.push_back(HumanData("human"));

	PlusMemberCreate();
}

std::string RoomLayer::RandomHero(const std::vector<std::string>& heroID)
{
	int num = heroID.size();
	int a = rand() % num;
	return heroID.at(a);
}

void RoomLayer::PlusMemberCreate()
{
	for (int i = 1; i <= 9; ++i)
	{
		auto box1 = MenuItemImage::create("ui/box.png", "ui/box.png");
		auto box2 = MenuItemImage::create("ui/box_robot.png", "ui/box_robot.png");
		auto box3= MenuItemImage::create("ui/box_human.png", "ui/box_human.png");
		assert(box1 != NULL);
		assert(box2 != NULL);
		assert(box3 != NULL);
		//�����������Ļ����callback����Ҫ��һ��
		auto box0 = MenuItemToggle::createWithCallback(CC_CALLBACK_1(RoomLayer::menuCloseCallback, this), box1, box2, box3, NULL);
		_figures.pushBack(box0);
		////����tag�������vector��ȡ
		//box0->setTag(i - 1);
		auto box = Menu::create(box0, NULL);
		this->addChild(box);

		if (i <= 5)
		{
			box->setPosition(Vec2(kVisibleSize.width / 2 + (i - 3) * 150, kVisibleSize.height / 2 + 200));
		}
		else
		{
			box->setPosition(Vec2(kVisibleSize.width / 2 + (i - 7) * 150, kVisibleSize.height / 2 - 200));
		}
		box->setContentSize(Size(50, 125));
	    
	}
}

void RoomLayer::SetButton()
{
	_current->removeChildByName("button1");
	_current->removeChildByName("button2");
	//����_figuresʵ�ָֻ�ʹ��(ʹ�û��ڷ�Χ��Forѭ��)
	for (auto item : _figures)
		item->setEnabled(true);
}

void RoomLayer::SetHero()
{
	std::string name;
	//for (auto temp : _humandata)
	//{
	//	//����֮����_humandata.get����ȡ��ɫӢ��
	//	name = PlistData::getDataByType(;
	//	name += " false";
	//	herodataVec.push_back(HeroData(name, PlistData::getDataByType(PlistData::DataType::ID)));
	//}
	auto heroVec = HeroFactory::getInstance()->getClassIDVec();
	srand(time(NULL));
	for (int i = 0; i < _member.getRobot(); ++i)
	{
		//֮����߸����������һ��hero��
		name = RandomHero(heroVec);
		name += " true";
		herodataVec.push_back(HeroData(name));
	}
}

void RoomLayer::menuCloseCallback(Ref* pSender)
{
	//������Ҫ�����˻���Ҫ��һ����ѡ��ѡ��֮�󴫸����Ȼ����һ����ҵĽ�ɫͼ���ԭ�������˵�ͼ���ס�ɣ�����֮֮����˵
	//������Լ�һ��ѡ��ť�ĵڶ��ε�������������ң�
	auto const item = dynamic_cast<MenuItemToggle*>(pSender);
	if (item)
	{
		_current = item;
		if (item->getSelectedIndex()==1)
		{
			//����_figuresʵ�������˵�����ʹ��(ʹ�û��ڷ�Χ��Forѭ��)
			for (auto item : _figures)
				item->setEnabled(false);
			Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
			auto button1 = Tools::ButtonCreate("������", Vec2(_current->getContentSize().width / 2, _current->getContentSize().height/2 + 75), item);
			button1->setName("button1");
			button1->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
				{
					if (type == Widget::TouchEventType::ENDED)
					{
						Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
						_member.setRobot(true);
						_current->setName("robot");
						_current->setSelectedIndex(1);
						SetButton();
					}
				});
			//��������Ժ���һ���ص�������
			//
			//
			//
			//
			auto button2 = Tools::ButtonCreate("���", Vec2(_current->getContentSize().width / 2, _current->getContentSize().height/2 - 75), item);
			button2->setName("button2");
			button2->addTouchEventListener([&item, this](Ref*, Widget::TouchEventType type)
				{
					if (type == Widget::TouchEventType::ENDED)
					{
						Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
						/*_member.setHuman(true);
						_current->setName("human");*/
						_current->setSelectedIndex(0);
						SetButton();
					}
				});
		}
		else
		{
			item->setSelectedIndex(0);
			Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
			if (item->getName() == "robot")
				_member.setRobot(false);
			else if (item->getName() == "human")
				_member.setHuman(false);
		}
	}
}

void RoomLayer::setSelf(const std::string& filename)
{
	if (_that != NULL)
	{
		_that->scheduleOnce([filename](float dlt)
			{
				_that->_self->runAction(RemoveSelf::create());
				_that->_self = Tools::ButtonCreateN(Vec2(_that->kVisibleSize.width / 2 + (-2) * 150, _that->kVisibleSize.height / 2 - 200)
					, filename, _that);
				_that->_self->addTouchEventListener([](Ref*, Widget::TouchEventType type)
					{
						if (type == Widget::TouchEventType::ENDED)
						{
							Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
							auto changeFigure = FigureLayer::create();
							assert(changeFigure != 0);
							_that->addChild(changeFigure);
							Tools::SwitchScene(changeFigure, Tools::SwitchSceneType::Down);
						}
					});
			}, 0.5f, "delaytime");
	}
}

