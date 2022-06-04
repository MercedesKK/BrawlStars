//2151396 �ž���

#include"cocos2d.h"
#include "View/GameScene.h"
#include "Const/Const.h"
#include "Participant/PlayerParticipant.h"
#include "Participant/ParticipantNode.h"
#include "Participant/RobotParticipant.h"
#include <sstream>

/**
* @brief ��ʼ��Ӣ��
*/

extern std::vector<HeroData> herodataVec;

void GameScene::addHeroPlayer() 
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//��ʼ��λ�ö����
	initObjPosition();
	std::vector<int> tenRandVector = randTenNumberVec(static_cast<int>(herodataVec.size()));

	size_t heronum = herodataVec.size(); 

	//����һ������Ϊ����
	for (int i = 0; i < heronum; i++)
	{
		//��ʼ������
		std::istringstream temp(herodataVec[i].name_isRobot);
		std::string heroname;
		std::string isRobot;
		temp >> heroname;
		temp >> isRobot;

		Participant* player;
		if (isRobot == "true")
		{
			player = Robot::createWithHeroID(heroname);
		}
		else if (isRobot == "false")
		{
			player = Player::createWithHeroID(heroname);
		}

		_heroVec.push_back(player);
		player->setPosition(_tenPosition[tenRandVector[i]]);
		this->addChild(player, kHeroPriority, i + 10);

		//��������
		if (i == 0)
		{
			_player = _heroVec[0];
			dynamic_cast<Player*>(_player)->setKeyboardListener(true);
			dynamic_cast<Player*>(_player)->setTouchListener(true);
		}
	}
}