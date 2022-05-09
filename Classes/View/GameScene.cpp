#include "GameScene.h"
#include"Hero/HeroSprite.h"
#include"Hero/BeiyaHero.h"
#pragma execution_character_set("utf-8")  

bool GameScene::init()
{
	if (!Scene::init())
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

	

	// Add BeiyaHero
	_player = Beiya::createBeiya();
	_player->setPosition(Vec2(100, 100));
	this->addChild(_player);
	this->scheduleUpdate();
	
	return true;
}

/**
* @fn update
* @brief update 
*/
void GameScene::update(float dt)
{
	//use the keyboard to move hero
	_player->setKeyboardListener(true);
	setViewPointByPlayer(_player->getPosition());

	//test zjk
	isColliding(_player->getPosition());
}