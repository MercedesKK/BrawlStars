#pragma once
#include "cocos2d.h"
#include "Const/Const.h"

/**
* @author �ž���
* @brief ��Ʒ��
*/
class Item : public cocos2d::Node  
{
public:
	void bindSprite(cocos2d::Sprite* sprite);
	cocos2d::Sprite* getSprite(); 

	void generatePhysicalBody(std::string message, int itemTag);

protected:
	cocos2d::Sprite* _sprite;
};
