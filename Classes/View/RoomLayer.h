#pragma once

#include "cocos2d.h"
#include"ui/CocosGUI.h"
#include"Tool/Member.h"

class Member;

/**
* @brief ���䳡��
*/
class RoomLayer :public cocos2d::Layer
{
public:

	CREATE_FUNC(RoomLayer);

	/**
    * @brief ��Ա�ĵ������
    */
	void menuCloseCallback(Ref* pSender);


private:

	virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);

	RoomLayer() :kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize())
		, _bg(NULL), _choose_hero(NULL), _start(NULL), _back(NULL), _vs(NULL), _robots(NULL), _member() {};

	//����

	//**
 //   * @brief ���ð�ť��add������,���������ذ汾
 //   * @param (Vec2 position)λ��
 //   * @param (std::string pic_name)ͼƬ·��
	//* @param (std::string words)���ְ�ť����ʾ����
 //   */
	//cocos2d::ui::Button* ButtonCreate(const cocos2d::Vec2&& position, const std::string&& pic_name);
	//cocos2d::ui::Button* ButtonCreate(const std::string&& words, const cocos2d::Vec2&& position);

	/**
	* @brief ����6�������Ա�򣬰���һ���������5��+��
	*/
	void MemberCreate();

	/**
	* @brief 5��+��
	*/
	void PlusMemberCreate();

private:

	const cocos2d::Size kVisibleSize;

	//��¼���汳��
	cocos2d::ui::Scale9Sprite* _bg;

	//ѡ��hero��ť
	cocos2d::ui::Button* _choose_hero;

	//��ʼ��ս��ť
	cocos2d::ui::Button* _start;
	
	// ���ذ�ť
	cocos2d::ui::Button* _back;
	
	//vs��ʶ
	cocos2d::Label* _vs;

	//�Զ���ȫ�����˰�ť
	cocos2d::ui::Button* _robots;

	////�з�����
	//Member _enemy;

	////�ҷ�����
	//Member _our;

	Member _member;

	//��Ա
	cocos2d::Vector<cocos2d::MenuItemToggle*> _figures;

};

