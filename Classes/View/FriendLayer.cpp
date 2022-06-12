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
#include"Net/Client.h"
#include"Tool/Data.h"
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

	Client::getInstance()->sendData("?FR");
	std::thread recvThread = std::thread(&FriendLayer::RecvFriend, this);
	recvThread.detach();

	////��Ӻ���
	//_addFriend = Tools::ButtonCreate("��Ӻ���", Vec2(kVisibleSize.width / 2, kVisibleSize.height * 0.2f), this);
	//_addFriend->addTouchEventListener([this](Ref*, Widget::TouchEventType type)
	//	{
	//		if (type == Widget::TouchEventType::ENDED)
	//		{
	//			Setting::getInstance()->GoSoundEffect("audio/click_effect.mp3");
	//			//���ı��������_text
	//		}
	//	});

	//���Ӧ���д����϶�ȡ�������ݣ�Ȼ�������б�emmmȻ�����֧�ֲ鿴����һЩ���ݺ�˽�ģ�

	return true;
}

bool FriendLayer::RecvFriend()
{
	Sleep(1000);
	if (Client::getInstance() != NULL)
		Client::getInstance()->updateFriend(_friend);
	if (_friend.size() != 0)
	{
		addFriend();
		return true;
	}
	else
		return false;
}

void FriendLayer::addFriend()
{
	std::string value;
	std::vector<std::string> info(4);
	for (unsigned int i = 0; i < _friend.size(); ++i)
	{
		value = _friend.at(i);
		unsigned int poi1 = 0;
		int num = 0;
		for (unsigned int poi2 = 0; poi2 < value.size(); ++poi2)
		{
			if (value.at(poi2) == ':')
			{
				info.at(num++) = value.substr(poi1, poi2 - poi1);
				poi1 = poi2 + 1;
			}
		}
		info.at(num++) = value.substr(poi1, value.size() - poi1);

		if(info.at(3)==PlistData::getDataByType(PlistData::DataType::ID))
			continue;

		auto head = Sprite::create(info.at(0));
		head->setPosition(kVisibleSize.width / 2 - 200, kVisibleSize.height * 0.1f*(9 - i));
		this->addChild(head);

		auto name = Tools::LabelCreateSystem(Vec2(kVisibleSize.width / 2, kVisibleSize.height * 0.1f * (9 - i))
			, info.at(1), "΢���ź�", 36, this);

		auto cups = Tools::LabelCreateSystem(Vec2(kVisibleSize.width / 2 + 300, kVisibleSize.height * 0.1f * (9 - i))
			, "Cups:" + info.at(2), "΢���ź�", 36, this);

	}
}
