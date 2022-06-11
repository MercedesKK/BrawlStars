#include "SettlementScene.h"
USING_NS_CC;
using namespace ui;
//#define NDEBUG
#include<cassert>
#include "Tool/SceneManager.h"
#include"Tool/Tools.h"
#include"Tool/Data.h"
#include "Const/Const.h"
#include"Tool/LeaderBoard.hpp"
#pragma execution_character_set("utf-8")  

extern LeaderBoard<std::string, Rank> single;

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
	unsigned int ranking = single.rank(PlistData::getDataByType(PlistData::DataType::ID));
	assert(ranking <= 10 && ranking >= 1);
	unsigned int cups = single.find(PlistData::getDataByType(PlistData::DataType::ID))->second->second._trophy;

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

	auto label = Tools::LabelCreateTTF(Vec2(kVisibleSize.width / 2 - 450, kVisibleSize.height - 100), "�� " + Value(ranking).asString() + " ��", "fonts/arial.ttf", 75, this);

	_cups->setString("   " + Value(cups).asString());
	PlistData::WriteDataByType(PlistData::DataType::Cups, Value(Value(PlistData::getDataByType(PlistData::DataType::Cups)).asInt() + cups).asString());
}
