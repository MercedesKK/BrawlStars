#pragma once
#include "Item.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Const/Const.h"

class DiamondBuff : public Item
{
public:
	CREATE_FUNC(DiamondBuff);

	/**
	* @��ʼ����ʯ
	*/
	bool virtual init() override;

	enum class Buff
	{
		health = 0,
		attack = 1
	};

	////��ʱû��
	//void setDiamondPos(cocos2d::Vec2 position) { _DiamondPos = position; };

	//����ֵ��Ѫ��ֵ�͹���ֵ
	static int buffAttackOrHealth();
private:
	////��ʱû��
	//cocos2d::Vec2 _DiamondPos;
};