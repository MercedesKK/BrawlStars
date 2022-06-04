#include "GameScene.h"
#pragma execution_character_set("utf-8")  

extern std::vector<HeroData> herodataVec;

bool GameScene::init()
{
	if (!Scene::init() || !Scene::initWithPhysics())
		return false;

	//物理检测红框
	//this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);


	//这是王佳垚写的，我先停掉了，停在我这个地图界面

	/*auto label = Label::createWithSystemFont("游戏界面", "方正姚体", 50);
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


	//初始化地图
	addMap(cocos2d::random(1,3)); 
	//初始化障碍层
	addBarrier();
	//初始化草丛
	addGrass();
	//添加主角
	addHeroPlayer();
	//添加宝箱
	addBox();
	//添加毒圈
	addPoisonCircle();
	//添加计时器
	addTimer();
	//添加聊天室
	addChatBox();
	//添加物理引擎碰撞检测
	initializeContactListener();
	//添加聊天框监听
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
	//跟随主角
	setViewPointByPlayer(_player->getPosition());

	//更新 计时器 聊天室
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


