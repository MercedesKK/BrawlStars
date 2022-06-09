//2151396 �ž���

#pragma once

/**
* @class ChatBox
* @brief ������
*/

#include "cocos2d.h"
#include "Const/Const.h"
#include <vector>
#include <string>

extern std::vector<HeroData> herodataVec;

class ChatBox : public cocos2d::Sprite
{
	//ÿһ�ε�������Ϣ
	CC_SYNTHESIZE(std::string, _message, Message);

private:
	std::vector<std::string> _messages;
	std::vector<cocos2d::Label*> _labelMessages;
	cocos2d::Label* _labelInputMessage;
	std::string _defaultHeroName; 
	std::size_t _messageSize;

	int enterCount = 0;

public:
	/**
	* @fn switchKeycodeToChar
	* @brief ÿһ���ַ�ת����char
	*/
	static char switchKeycodeToChar(cocos2d::EventKeyboard::KeyCode keyCode);

	/**
	* @fn updateMessage
	* @brief ���������ÿһ���ַ�
	*  ���볤��С��15 | ����'*'      ///>����û����
	*/
	void updateMessage(char newchar);

	void enterToUpdateMessage();

	void backspaceTodateMessage();

	void setDefaultHeroName(std::string heroid);

	//void pushMessage(std::string newMessage);

	virtual bool init() override;

	CREATE_FUNC(ChatBox); 

	ChatBox();
};