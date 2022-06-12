#include "FigureLayer.h"
USING_NS_CC;
using namespace ui;
//#define NDEBUG
#include<cassert>
#include"Tool/Tools.h"
#include "MainScene.h"
#include "Tool/Data.h"
#include"Factory/HeroFactory.h"
#include"RoomLayer.h"


std::vector<std::string> FigureLayer::heroVec;

bool FigureLayer::init()
{
	if (!Layer::init())
		return false;

	//�������ɵ���¼�
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(FigureLayer::onTouchBegan, this);
	Tools::LayerSwallow(listener, this);

	//��ȡ����heroname��Ϣ
	if (heroVec.size() == 0)
		heroVec = HeroFactory::getInstance()->getClassIDVec();
	kNum = heroVec.size();

	//����
	_bg = Tools::SetBg(this);

	//��ȡ�����趨�Ľ�ɫ,��ý�ɫ����
	_figure = PlistData::getDataByType(PlistData::DataType::Figure);

	//���ذ�ť
	_back = Tools::ButtonCreate(Vec2(100, kVisibleSize.height - 100), "ui/back.png", this);
	_back->addTouchEventListener([this](Ref*, Widget::TouchEventType)
		{
			//ͬʱ���������ĺͷ��䳡����������
		    MainScene::GetMainScene()->SetFigure(_figure);
			RoomLayer::setSelf(_figure);
			PlistData::WriteDataByType(PlistData::DataType::Figure, _figure);
			//�������ϻ��µ�Ч��
			Tools::SwitchScene(this, Tools::SwitchSceneType::Up);
		});

	//������������ͼ��
	SetFigures();

	return true;
}

void FigureLayer::SetFigures()
{
	std::string name;
	auto heroVec= HeroFactory::getInstance()->getClassIDVec();
	for (int i = 1; i <= kNum; ++i)
	{
		//������������
		name = HeroFactory::getInstance()->createWithClassID(heroVec.at(i - 1))->getHeroPicture();
		Button* figure;
		figure = Tools::ButtonCreateN(Vec2(kVisibleSize.width / 2 - (2 - ((i-1)%3+1) ) * 250, kVisibleSize.height / 2 + 150 - (i  - 1) / 3 * 300)
			, name, this);
		//���ϸ��ϳ�ʼ���趨�򹴵Ľ�ɫ
		if (name == _figure)
			_select = Tools::SpriteCreate(figure->getPosition(), "ui/select.png", this);
		figure->addTouchEventListener([this](Ref* ref, Widget::TouchEventType type)
			{
				//��߱���ֱ��������������ʹ����&figure�������������������еĹ�����figure�ѱ��ͷţ���Ҫ��ref��ȡ�������ť
				if (type == Widget::TouchEventType::ENDED)
				{
					auto button = dynamic_cast<Button*>(ref);
					_figure = button->getNormalFile().file;
					auto distory = RemoveSelf::create();
					_select->runAction(distory);
					_select = Tools::SpriteCreate(button->getPosition(), "ui/select.png", this);
				}
			});
	}
}
