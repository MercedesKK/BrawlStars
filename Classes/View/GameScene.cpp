#include "GameScene.h"
#include"Hero/HeroSprite.h"
#include"Hero/BeiyaHero.h"
#pragma execution_character_set("utf-8")  

extern std::vector<HeroData> herodataVec;

bool GameScene::init()
{
	if (!Scene::init() || !Scene::initWithPhysics())
		return false;
	//���ó�����tag
	this->setTag(SceneTag::kGameSceneTag);
	
	//��ʼ��ʱ
	auto timer = MyTimer::create();
	this->addChild(timer, kTimerPriority);


	//��������
	this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);


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
	
	
	this->scheduleUpdate();
	



	return true;
}

/**
* @fn update
* @brief update the position of hero and map
*/
void GameScene::update(float dt)
{
	setViewPointByPlayer(_player->getPosition());

	//
	if (poisonCircleDown->getPosition().y < poisonCircleMax)
	{
		poisonCircleDown->setPosition(poisonCircleDown->getPosition().x, poisonCircleDown->getPosition().y + poisonCircleMarch);
	}

	if (poisonCircleUp->getPosition().y > 0)
	{
		poisonCircleUp->setPosition(poisonCircleUp->getPosition().x, poisonCircleUp->getPosition().y - poisonCircleMarch);
	}

	if (poisonCircleLeft->getPosition().x < poisonCircleMax)
	{
		poisonCircleLeft->setPosition(poisonCircleLeft->getPosition().x + poisonCircleMarch, poisonCircleLeft->getPosition().y );
	}

	if (poisonCircleRight->getPosition().x > 0)
	{
		poisonCircleRight->setPosition(poisonCircleRight->getPosition().x - poisonCircleMarch , poisonCircleRight->getPosition().y );
	}
}


