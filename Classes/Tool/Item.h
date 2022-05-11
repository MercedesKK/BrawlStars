#pragma once
#include "cocos2d.h"
#include "Const/Const.h"

/**
* @class Item
* @brief ��Ʒ��
*/
class Item : public cocos2d::Node
{
public:
	void bindSprite(cocos2d::Sprite* sprite);
	cocos2d::Sprite* getSprite();

	/**
	* @fn generatePhysicalBody
	* @brief ���������������
	* @param tag and name
	*/
	void generatePhysicalBody(std::string message, int itemTag);

protected:
	//���屾��
	cocos2d::Sprite* _sprite;
};
