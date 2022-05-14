#pragma once

#include "cocos2d.h"
#include"ui/CocosGUI.h"

/**
* @brief ������Ϣ����
*/
class InforLayer :public cocos2d::Layer
{
public:

	CREATE_FUNC(InforLayer);

	/**
    * @brief ��־��ʲô���͵���Ϣ
    */
	enum class Information
	{
		Name,
		Cup,
		Money,
		MaxRank,
	};

	/**
    * @brief ����info����
    */
	void Change(const std::string& newinfo, Information infoType);

private:

	virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*) { return true; }

	InforLayer() :kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize())
		, _bg(NULL), _back(NULL), _profile(NULL), _change_name(NULL), kInfos(3) {};

	/**
    * @brief �ṩ����info��ǩ�ķ�����һ������+һ�����֣�
	* @param (Information info)����
	* @param (const int num)��ʼ��ʾֵ
    */
	void setInfo(Information infoType, const std::string&& info = "");

	/**
	* @brief �ı������¼�
	*/
	void TextFieldEvent(Ref* pSender, cocos2d::ui::TextField::EventType type);

private:

	const cocos2d::Size kVisibleSize;

	//���û��汳��
	cocos2d::ui::Scale9Sprite* _bg;

	//���ذ�ť
	cocos2d::ui::Button* _back;

	//ͷ��
	cocos2d::ui::Button* _profile;

	//���¿ɸı��info����
	cocos2d::Vector<cocos2d::Label*> _infomation;

	//�������ְ�ť
	cocos2d::ui::Button* _change_name;

	//�ı���
	cocos2d::ui::TextField* _text;

	//ͷ��������ڳ�ʼ���ĵط���
	const int kInfos;

};
