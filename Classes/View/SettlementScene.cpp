#include "SettlementScene.h"
USING_NS_CC;
using namespace ui;
//#define NDEBUG
#include<cassert>
#include "Tool/SceneManager.h"
#include"Tool/Tools.h"
#include"Tool/Data.h"
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

	//����Ϸ�������ж����������ݣ�
	Win();

	//��ɫ����
	_figure = Tools::SetBg(PlistData::getDataByType(PlistData::DataType::Figure), this);

	return true;
}

void SettlementScene::Win()
{
	//����Ϸ�������Ĳ�������߾���ֱ��win��
	std::string ranking = "1";
	assert(Value(ranking).asInt() <= 10 && Value(ranking).asInt() >= 1);

	//��ý�����Ŀ
	auto cupslabel = Tools::LabelCreateSystem(Vec2(kVisibleSize.width / 2, kVisibleSize.height * 0.9f), "��ý���", "΢���ź�", 35, this);
	cupslabel->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
	_cups= Tools::LabelCreateSystem(Vec2(kVisibleSize.width / 2, kVisibleSize.height * 0.9f), "", "΢���ź�", 35, this);
	_cups->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);

	//��ý������(����ģʽ��ͬ�ı䣬��ֻ��һ��ģʽ�Ͷ�100��)
	auto moneylabel = Tools::LabelCreateSystem(Vec2(kVisibleSize.width / 2, kVisibleSize.height * 0.8f), "��ý��", "΢���ź�", 35, this);
	moneylabel->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
	_money = Tools::LabelCreateSystem(Vec2(kVisibleSize.width / 2, kVisibleSize.height * 0.8f), "   100", "΢���ź�", 35, this);
	_money->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	PlistData::WriteDataByType(PlistData::DataType::Money, Value(Value(PlistData::getDataByType(PlistData::DataType::Money)).asInt() + 100).asString());

	if (ranking == "1")
	{
		auto label = Tools::LabelCreateTTF(Vec2(kVisibleSize.width / 2 - 450, kVisibleSize.height - 100), "W I N", "fonts/arial.ttf", 75, this);
		_cups->setString("   2");
		PlistData::WriteDataByType(PlistData::DataType::Cups, Value(Value(PlistData::getDataByType(PlistData::DataType::Cups)).asInt() + 2).asString());
	}
	else
	{
		auto label = Tools::LabelCreateTTF(Vec2(kVisibleSize.width / 2 - 450, kVisibleSize.height - 100), "�� " + ranking + " ��", "fonts/arial.ttf", 75, this);
		if (Value(ranking).asInt() <= 3)
		{
			_cups->setString("   1");
			PlistData::WriteDataByType(PlistData::DataType::Cups, Value(Value(PlistData::getDataByType(PlistData::DataType::Cups)).asInt() + 1).asString());
		}
		else if (Value(ranking).asInt() <= 6)
			_cups->setString("   0");
		else
		{
			_cups->setString("   -1");
			PlistData::WriteDataByType(PlistData::DataType::Cups, Value(Value(PlistData::getDataByType(PlistData::DataType::Cups)).asInt() - 1).asString());
		}
	}
}
