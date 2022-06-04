#include "GameScene.h"
#pragma execution_character_set("utf-8")  

extern std::vector<HeroData> herodataVec;

bool GameScene::init()
{
	if (!Scene::init() || !Scene::initWithPhysics())
		return false;

	//��������
	//this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);


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
	addMap(cocos2d::random(1,3)); 
	//��ʼ���ϰ���
	addBarrier();
	//��ʼ���ݴ�
	addGrass();
	//�������
	addHeroPlayer();
	//��ӱ���
	addBox();
	//��Ӷ�Ȧ
	addPoisonCircle();
	//��Ӽ�ʱ��
	addTimer();
	//���������
	addChatBox();
	//�������������ײ���
	initializeContactListener();
	//�����������
	initTouchAndKeyListener();
	

	this->scheduleUpdate();
	
	return true;
}

/**
* @fn update
* @brief update the position of hero and map
*/
void GameScene::update(float dt)
{
	//��������
	setViewPointByPlayer(_player->getPosition());

	//���� ��ʱ�� ������
	updateMyTimerPosition();
	updateChatBoxPosition();

	auto pos = _player->getPosition();
	//log("ssx:%f", pos.x);
	//log("ssy:%f", pos.y);
	if (poisonCircleDown->getPosition().y > poisonCircleMax / 2)
	{
		poisonCircleDown->setPosition(poisonCircleDown->getPosition().x, poisonCircleDown->getPosition().y - poisonCircleMarch);
	}
	if (poisonCircleUp->getPosition().y < poisonCircleMax / 2)
	{
		poisonCircleUp->setPosition(poisonCircleUp->getPosition().x, poisonCircleUp->getPosition().y + poisonCircleMarch);
	}
	if (poisonCircleLeft->getPosition().x > poisonCircleMax / 2)
	{
		poisonCircleLeft->setPosition(poisonCircleLeft->getPosition().x - poisonCircleMarch, poisonCircleLeft->getPosition().y);
	}
	if (poisonCircleRight->getPosition().x < poisonCircleMax / 2)
	{
		poisonCircleRight->setPosition(poisonCircleRight->getPosition().x + poisonCircleMarch, poisonCircleRight->getPosition().y);
	}
}


