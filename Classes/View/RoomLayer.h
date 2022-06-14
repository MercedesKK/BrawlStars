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

	/**
    * @brief �����Լ��Ľ�ɫ
    */
	static void setSelf(const std::string& filename);

private:

	virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);

	RoomLayer() :kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize())
		, _bg(NULL), _choose_hero(NULL), _start(NULL), _back(NULL), _vs(NULL), _robots(NULL), _member(), _self(NULL), _current(NULL) {};

	~RoomLayer() { _that = NULL; }

	/**
	* @brief ����9�������Ա�򣬰���һ���������5��+��
	*/
	void MemberCreate();

	/**
    * @brief ������������Ӣ��
    */
	std::string RandomHero(const std::vector<std::string>&);

	/**
	* @brief 9��+��
	*/
	void PlusMemberCreate();

	/**
	* @brief ����ѡ������˻�����Ұ�ťʱ������ť���ܵ㻹�и��ֹ�ͬ����
	*/
	void SetButton();

	/**
	* @brief ����Ӣ�����ݸ���Ϸ����
	*/
	void SetHero();

private:

	const cocos2d::Size kVisibleSize;

	static RoomLayer* _that;

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

	Member _member;

	std::vector<HumanData> _humandata;

	//��Ա
	cocos2d::Vector<cocos2d::MenuItemToggle*> _figures;

	//self
	cocos2d::ui::Button* _self;

	//��ǰ������Ա
	cocos2d::MenuItemToggle* _current;

};

