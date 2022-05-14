#pragma once

#include"cocos2d.h"
#include"ui/CocosGUI.h"

/**
* @brief �����࣬�ṩ���ַ���
*/
class Tools
{
public:

	/**
	* @brief ��ʼ��һ��static��Ա�����Ա����ʹ��
	*/
	static void set() { kVisibleSize = cocos2d::Director::getInstance()->getVisibleSize(); }

	/**
	* @brief �ṩʹ�þŹ���������ͼƬ��ť�����ְ�ť�ķ�װ����
	* @param (Vec2 position)λ��
    * @param (std::string pic_name)ͼƬ·��
    * @param (std::string words)���ְ�ť����ʾ����
    * @param (Scene* that)������thisָ��
    */
	static cocos2d::ui::Button* ButtonCreate(const cocos2d::Vec2&& position, const std::string&& pic_name, cocos2d::Node* that);
	static cocos2d::ui::Button* ButtonCreate(const std::string&& words, const cocos2d::Vec2&& position, cocos2d::Node* that);
	static cocos2d::ui::Button* ButtonCreate(const cocos2d::Vec2&& position, const std::string&& words, const std::string&& pic_name
		                                   , const std::string&& pic_name_s, cocos2d::Node* that);
	////��ֵ�汾
	//static cocos2d::ui::Button* ButtonCreate(const cocos2d::Vec2&& position, const std::string&& words, const std::string& pic_name
 //                                          , const std::string& pic_name_s, cocos2d::Node* that);
	//��ͨͼƬ��ť
	static cocos2d::ui::Button* ButtonCreateN(const cocos2d::Vec2&& position, const std::string&& pic_name, cocos2d::Node* that);
	static cocos2d::ui::Button* ButtonCreateN(const cocos2d::Vec2&& position, const std::string& pic_name, cocos2d::Node* that);

	/**
	* @brief ����layer��û����¼�
	* @param (Scene* that)������thisָ��
	* @param (EventListenerTouchOneByOne* listener�����listener
	*/
	static void LayerSwallow(cocos2d::EventListenerTouchOneByOne* listener, cocos2d::Layer* that);

	/**
	* @brief ���ñ���
	* @param (Scene* that)������thisָ��
	* @param (const std::string&&filename)ͼƬ��ַ
	*/
	static cocos2d::Sprite* SetBg(const std::string&& filename, cocos2d::Node* that);
	static cocos2d::Sprite* SetBg(const std::string& filename, cocos2d::Node* that);
	static cocos2d::ui::Scale9Sprite* SetBg(cocos2d::Node* that);

	/**
	* @brief �л�������action��һЩ����
	*/
	enum class SwitchSceneType 
	{
		Down,
		Up,
		FadeIn,
		FadeOut,
		Turn,
		//��������õ�
		LeftToRight,
		RightToLeft
	};

	/**
	* @brief �л�����
	* @param (cocos2d::Node*)��Ӷ����Ľڵ�
	* @param (SwitchSceneType)����
	*/
	static void SwitchScene(cocos2d::Node*, SwitchSceneType);

	/**
	* @brief ��װ����slider
	* @param (cocos2d::Node*)Ҫ��ӽ��Ľڵ�
	*/
	static cocos2d::ui::Slider* SliderCreate(cocos2d::Vec2&& pos, std::string&& bar, std::string&& Texture, std::string&& ball, cocos2d::Node*);

	/**
	* @brief ��װ��������Menu
	* @param (cocos2d::Node*)Ҫ��ӽ��Ľڵ�
	* @param (cocos2d::ccMenuCallback& callback)�ص�����
	*/
	static cocos2d::Menu* MenuCreate(cocos2d::Vec2&& pos,std::string&& item, std::string&& item_s
		, const cocos2d::ccMenuCallback& callback , cocos2d::Node* that);

	/**
	* @brief ��װ����Label
	* @param (cocos2d::Node*)Ҫ��ӽ��Ľڵ�
	* @param (cocos2d::ccMenuCallback& callback)�ص�����
	*/
	static cocos2d::Label* LabelCreateTTF(cocos2d::Vec2&& pos, const std::string& words, std::string&& ttf, float size, cocos2d::Node*);
	static cocos2d::Label* LabelCreateSystem(const cocos2d::Vec2& pos, const std::string& words, std::string&& ttf, float size, cocos2d::Node*);

	/**
	* @brief ��װ��������
	* @param (cocos2d::Node*)Ҫ��ӽ��Ľڵ�
	*/
	static cocos2d::Sprite* SpriteCreate(const cocos2d::Vec2& pos, std::string&& filename, cocos2d::Node*);

private:

	//���ﲻ��ֱ�Ӹ�kVisibleSize��director��ȡ����Ϊȫ�ֱ�����director��ȡvisiblesize֮ǰ���Ѿ����ø�ֵ
	static cocos2d::Size kVisibleSize;

	Tools();

};

