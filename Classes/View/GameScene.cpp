#include "GameScene.h"
#include"Hero/HeroSprite.h"
#include"Hero/BeiyaHero.h"
#pragma execution_character_set("utf-8")  

bool GameScene::init()
{
	if (!Scene::initWithPhysics()) 
		return false;

	//�������ш�д�ģ�����ͣ���ˣ�ͣ���������ͼ����

	/*auto label = Label::createWithSystemFont("��Ϸ����", "����Ҧ��", 50);
	assert(label);
	label->setPosition(kVisibleSize.x / 2, kVisibleSize.y / 2 - 100);
	this->addChild(label);

	auto _continue = Button::create("CloseNormal.png");
	assert(_continue);
	_continue->setPosition(kVisibleSize / 2);
	this->addChild(_continue);
	_continue->addClickEventListener([](Ref*)
		{
			SceneManager::getInstance()->changeScene(SceneManager::EnumSceneType::en_SettlementScene);
		});*/

	//��ʼ����ͼ
	initMap();
	//��ʼ���ϰ���
	createBarrier();
	//��ʼ������
	addRandomBox();

	// Add BeiyaHero
	_player = Beiya::createBeiya();
	_player->setPosition(Vec2(100, 100));
	this->addChild(_player);
	this->scheduleUpdate();
	

	poisonCircle* _layer= poisonCircle::create();
	this->addChild(_layer);
	return true;
}

/**
* @fn update
* @brief update the position of hero and map
*/
void GameScene::update(float dt)
{
	//use the keyboard to move hero
	_player->setKeyboardListener(true);
	setViewPointByPlayer(_player->getPosition());
}
bool poisonCircle::init()
{
	if (!Scene::init())
		return false;
	
	
	//��ʱ������������Ϸ��ʼ֮��30��ſ�ʼ����,��ż�����Ҫ��15�Σ��೤ʱ����������ӵ�����������ͼ�ˣ�ÿ3�����һ��
	schedule(SEL_SCHEDULE(&poisonCircle::updatepoisonCircle), 3.0f, 15, 10.0f);

	return true;
}
//�ӱ�ǩ������
void poisonCircle::updatepoisonCircle(float dt)
{
	//��Ȧ
	poisonCircleDown = cocos2d::Sprite::create("ToxicFog.png");
	poisonCircleDown->setPosition(2048, 960 - 1000);
	addChild(poisonCircleDown);
	/*poisonCircleUp = cocos2d::Sprite::create("ToxicFog.png");
	poisonCircleUp->setPosition(2048, 1000 - 960);
	addChild(poisonCircleUp);
	poisonCircleLeft = cocos2d::Sprite::create("ToxicFog.png");
	poisonCircleLeft->setPosition(960 - 1000, 2048);
	addChild(poisonCircleLeft);
	poisonCircleRight = cocos2d::Sprite::create("ToxicFog.png");
	poisonCircleRight->setPosition(960 - 1000, 2048);
	addChild(poisonCircleRight);*/

	if (poisonCircleDown->getPosition().y < poisonCircleMax)
	{
		poisonCircleDown->setPosition(poisonCircleDown->getPosition().x, poisonCircleDown->getPosition().y + poisonCircleMarch);
	}

	//if (poisonCircleUp->getPosition().y < poisonCircleMax)
		/*{
			poisonCircleUp->setPosition(poisonCircleUp->getPosition().x, poisonCircleUp->getPosition().y + poisonCircleMarch);
		}
		if (poisonCircleLeft->getPosition().y < poisonCircleMax)
		{
			poisonCircleLeft->setPosition(poisonCircleLeft->getPosition().x, poisonCircleLeft->getPosition().y + poisonCircleMarch);
		}
		if (poisonCircleRight->getPosition().y < poisonCircleMax)
		{
			poisonCircleRight->setPosition(poisonCircleRight->getPosition().x, poisonCircleRight->getPosition().y + poisonCircleMarch);
		}*/
	//��������
}


