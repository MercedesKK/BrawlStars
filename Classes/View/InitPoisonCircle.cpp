//2152590 ����

#include "View/GameScene.h"

bool poisonCircle::init()
{
	if (!Scene::init())
		return false;

	//��ʱ������������Ϸ��ʼ֮��...�ſ�ʼ����,��ż�����Ҫ��15�Σ��೤ʱ����������ӵ�����������ͼ�ˣ�ÿ3�����һ��
	schedule(SEL_SCHEDULE(&poisonCircle::updatepoisonCircle), 3.0f, 15, 3.0f);

	return true;
}
//�ӱ�ǩ������
/**
* @fn updatepoisonCircle
* @brief moving the poisoncircle
*/
void poisonCircle::updatepoisonCircle(float dt)
{

	//��Ȧ��ʼê��λ��
	poisonCircleDown = cocos2d::Sprite::create("circledown.png");
	poisonCircleDown->setPosition(1200, 0);
	addChild(poisonCircleDown);
	poisonCircleUp = cocos2d::Sprite::create("circleup.png");
	poisonCircleUp->setPosition(1200, 2400);
	addChild(poisonCircleUp);
	poisonCircleLeft = cocos2d::Sprite::create("circleleft.png");
	poisonCircleLeft->setPosition(0, 1200);
	addChild(poisonCircleLeft);
	poisonCircleRight = cocos2d::Sprite::create("circleright.png");
	poisonCircleRight->setPosition(2400, 1200);
	addChild(poisonCircleRight);


	if (poisonCircleDown->getPosition().y < poisonCircleMax)
	{
		poisonCircleDown->setPosition(poisonCircleDown->getPosition().x, poisonCircleDown->getPosition().y + poisonCircleMarch);
	}

	if (poisonCircleUp->getPosition().y < poisonCircleMax)
	{
		poisonCircleUp->setPosition(poisonCircleUp->getPosition().x, poisonCircleUp->getPosition().y + poisonCircleMarch);
	}
	if (poisonCircleLeft->getPosition().y < poisonCircleMax)
	{
		poisonCircleLeft->setPosition(poisonCircleLeft->getPosition().x, poisonCircleLeft->getPosition().y + poisonCircleMarch);
	}
	if (poisonCircleRight->getPosition().y < poisonCircleMax)
	{
		poisonCircleRight->setPosition(poisonCircleRight->getPosition().x, poisonCircleRight->getPosition().y + poisonCircleMarch);
	}

	//��������
	float downHeight = poisonCircleDown->getPosition().y;
	//���ø���
	auto downpoisonBody = PhysicsBody::createBox(Size(2400, downHeight));
	poisonCircleDown->addComponent(downpoisonBody);
	poisonCircleDown->getPhysicsBody()->setDynamic(false);
	poisonCircleDown->getPhysicsBody()->setCategoryBitmask(0x10);
	poisonCircleDown->getPhysicsBody()->setContactTestBitmask(0x10);
	poisonCircleDown->getPhysicsBody()->setGravityEnable(false);


	float upHeight = poisonCircleUp->getPosition().y;
	auto uppoisonBody = PhysicsBody::createBox(Size(2400, upHeight));
	poisonCircleUp->addComponent(uppoisonBody);
	poisonCircleUp->getPhysicsBody()->setDynamic(false); //��̬����
	poisonCircleUp->getPhysicsBody()->setCategoryBitmask(0x10);
	poisonCircleUp->getPhysicsBody()->setContactTestBitmask(0x10);

	float leftHeight = poisonCircleLeft->getPosition().y;
	auto leftpoisonBody = PhysicsBody::createBox(Size(2400, leftHeight));
	poisonCircleLeft->addComponent(leftpoisonBody);
	poisonCircleLeft->getPhysicsBody()->setDynamic(false);
	poisonCircleLeft->getPhysicsBody()->setCategoryBitmask(0x10);
	poisonCircleLeft->getPhysicsBody()->setContactTestBitmask(0x10);


	float rightHeight = poisonCircleRight->getPosition().y;
	auto rightpoisonBody = PhysicsBody::createBox(Size(2400, rightHeight));
	poisonCircleRight->addComponent(rightpoisonBody);
	poisonCircleRight->getPhysicsBody()->setDynamic(false);
	poisonCircleRight->getPhysicsBody()->setCategoryBitmask(0x10);
	poisonCircleRight->getPhysicsBody()->setContactTestBitmask(0x10);

}
