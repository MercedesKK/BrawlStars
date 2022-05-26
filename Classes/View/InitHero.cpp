/**
* @author �ž���
* ��ʼ��Ӣ��
*/
#include"cocos2d.h"
#include "View\GameScene.h"
#include "Const/Const.h"
#include "Hero/Robot.hpp"
#include <sstream>

extern std::vector<HeroData> herodataVec;

void GameScene::addHeroPlayer() 
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//��ʼ��λ�ö����
	initObjPosition();
	std::vector<int> tenRandVector = randTenNumberVec(10);


	//����һ������Ϊ����
	for (int i = 0; i < 1; i++)
	{
		//��ʼ������
		Hero* player = nullptr;
		
		std::istringstream temp(herodataVec[i].name_isRobot);
		std::string heroname;
		std::string isRobot;
		temp >> heroname;
		temp >> isRobot;

		if (heroname == "Beiya")
		{
			if (isRobot == "true")
				/*player = Robot<Beiya>::createRobot()*/;
			else if(isRobot == "false")
			{
				player = Beiya::createBeiya();
			}

			_heroVec.push_back(player);
			player->setPosition(_tenPosition[tenRandVector[i]]);
			this->addChild(player, kHeroPriority, i+10);
		}
		///��else if�������͵Ľ�ɫ
	}


	//��������
	//_player = dynamic_cast<Hero*>(this->getChildByTag(10));
	_player = _heroVec[0];

}