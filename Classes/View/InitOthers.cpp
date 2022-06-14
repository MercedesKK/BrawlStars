//2151396 �ž���

#include "View/GameScene.h"
#include "Const/Const.h"

using namespace std;
USING_NS_CC;

extern std::vector<HeroData> herodataVec;

/********************************** ��ʱ�� *****************************************/

/**
* @brief ��ʼ����ʱ��
*/
//void GameScene::addTimer()
//{
//	_timer = MyTimer::create();
//	this->addChild(_timer, kTimerPriority);
//
//}
//
//void GameScene::updateMyTimerPosition()
//{
//	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
//
//	cocos2d::Label* tmptimerInfo = _timer->getMyTimerInfo();
//	cocos2d::Sprite* tmptimerInfoBG = _timer->getMyTimerInfoBG();
//
//	tmptimerInfoBG->setPosition(this->destPos(this->getHero()->getPosition()) + cocos2d::Vec2(-visibleSize.width / 2, visibleSize.height / 2));
//	tmptimerInfo->setPosition(this->destPos(this->getHero()->getPosition()) + cocos2d::Vec2(55 - visibleSize.width / 2, visibleSize.height / 2));
//	tmptimerInfo->setString((_timer->getHour() + ":" + _timer->getMinute() + ":" + _timer->getSecond()));
//}


/********************************** ������ *****************************************/

/**
* @brief ��ʼ��������
*/
void GameScene::addChatBox()
{
	//�����Ұ�ť
	_chatboxSwitch = Sprite::create("ChatBox/ChatBox.png");
	_chatboxSwitch->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	this->addChild(_chatboxSwitch);
	_chatboxSwitch->setGlobalZOrder(kFightUI);

	//�����
	_chatBox = ChatBox::create();
	_chatBox->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	this->addChild(_chatBox);
	_chatBox->setGlobalZOrder(kFightUI);
	_chatBox->setVisible(false);
}

void GameScene::updateChatBoxPosition()
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	//���찴ť
	_chatboxSwitch->setPosition(this->destPos(this->getHero()->getPosition()) + cocos2d::Vec2(visibleSize.width / 2, -visibleSize.height / 2));

	//�����
	_chatBox->setPosition(this->destPos(this->getHero()->getPosition()) + cocos2d::Vec2(visibleSize.width / 2, -visibleSize.height / 2 + _chatboxSwitch->getContentSize().height));
}


/******************************* ������ ************************************/


bool GameScene::onTouchBegan(Touch* touch, Event* event)
{
	Rect worldchatboxSwitch = Rect(_chatboxSwitch->getPosition().x-46, _chatboxSwitch->getPosition().y, 46, 41);
	auto touchlocation = _player->convertToNodeSpace(touch->getLocation());

	//���п���
	if (worldchatboxSwitch.containsPoint(touchlocation))
	{
		if (_isChatboxOpen)
		{
			_isChatboxOpen = false;
			_chatBox->setVisible(false);
			return false;
		}
		_isChatboxOpen = true;
		_chatBox->setVisible(true);
		return false;
	}

	return true;
}

bool GameScene::onPressKey(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (_isChatboxOpen)
	{
		if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
		{
			_chatBox->enterToUpdateMessage(); 
		} 
		else if (keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE)
		{
			_chatBox->backspaceTodateMessage();
		}
		else
		{
			_chatBox->updateMessage(ChatBox::switchKeycodeToChar(keyCode));
		}
	}

	return true;
}

bool GameScene::onReleaseKey(EventKeyboard::KeyCode keyCode, Event* event)
{

	return false;
}

void GameScene::initTouchAndKeyListener()
{
	//��������������
	_gmlistenerTouch = EventListenerTouchOneByOne::create();
	//�󶨼����¼�
	_gmlistenerTouch->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_gmlistenerTouch, this);

	//�������̼�����
	_gmlistenerKeyBoard = EventListenerKeyboard::create();
	//�󶨼����¼�
	_gmlistenerKeyBoard->onKeyPressed = CC_CALLBACK_2(GameScene::onPressKey, this);
	_gmlistenerKeyBoard->onKeyReleased = CC_CALLBACK_2(GameScene::onReleaseKey, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_gmlistenerKeyBoard, this);

}


