#pragma once
#include "Item.h"
#include "cocos2d.h"
#include "Const/Const.h"

/**
* @ author:�ž���
* @ ʵ�ֱ�����
*/
class TreasureBox : public Item
{
public:
	CREATE_FUNC(TreasureBox);

	bool virtual init() override;
	
	TreasureBox* createBox();

protected:
	Item* _BoxItem;
};
