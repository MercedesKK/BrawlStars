#include "SettlementScene.h"
USING_NS_CC;
using namespace ui;
//#define NDEBUG
#include<cassert>
#include "Tool/SceneManager.h"
#include"Tool/Tools.h"
#pragma execution_character_set("utf-8")  

bool SettlementScene::init()
{
	if (!Scene::init())
		return false;

	//����
	_bg = Tools::SetBg("ui/settlementBg.png", this);

    //������ť
	_continue = Tools::ButtonCreate("�� ��", Vec2(kVisibleSize.width / 2, 70), this);
	_continue->addClickEventListener([](Ref*)
		{
			SceneManager::getInstance()->changeScene(SceneManager::EnumSceneType::en_MainScene);
		});

    //����Ϸ�������ж����ҷ��͵з���heroȻ�����Ƭ������,Ȼ���Ӧ��ս��ҲҪ��,�ڵ���+��ǩ��

	//����Ϸ�������ж���ʤ������Ȼ����ָ��һ����ʾwin
	WhoWin();

	return true;
}

void SettlementScene::WhoWin()
{
	//����Ϸ�������Ĳ�������߾���ֱ���ҷ�win��
	auto win = true;

	auto label = Label::createWithTTF("W I N", "fonts/arial.ttf", 75);
	assert(label != 0);
	this->addChild(label);

	if (win)
		label->setPosition(Vec2(kVisibleSize.width / 2 - 450, kVisibleSize.height - 100));
	else
		label->setPosition(Vec2(kVisibleSize.width / 2 + 450, kVisibleSize.height - 100));
}

void SettlementScene::ShowRecord()
{
	//��for���Ǹ��÷���������ͼƬ
	//ͬ�ϣ���������label����д��TOOl��ȣ��Ǹ������ָ�һ��
}
