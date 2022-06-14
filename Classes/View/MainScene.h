#pragma once

#include "cocos2d.h"
#include"ui/CocosGUI.h"
#include "Tool/ChatBox.h"

class LoadingScene;
class RoomLayer;
class SettingLayer;
class FigureLayer;
class InforLayer;
class MenuLayer;
class FriendLayer;

   /**
   * @brief ������
   */
class MainScene : public cocos2d::Scene
{
public:

    CREATE_FUNC(MainScene);

    /**
    * @brief ����������չʾ��ɫ
    */
    void SetFigure(const std::string& filename);

    /**
    * @brief ��ȡչʾ��ɫ���ļ�
    */
    std::string GetFigure()const;

    /**
    * @brief ȡ�õ�ǰ������
    */
    static  MainScene* GetMainScene() { return _that; }

    /**
    * @brief ����
    */
    static void Reset() { _that = NULL; }

    /**
    * @brief �޸�ͷ��
    */
    void SetInfo(const std::string& filename);

    /**
    * @brief �õ�ͷ��
    */
    std::string GetInfo();

    /**
    * @brief ���ڵ�½���ʼ���������ϵ�ͼ��
    */
    void Load();

private:

    virtual bool init();

    MainScene() :kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize())
        , _bg(NULL), _loading(NULL), _menu_button(NULL), _info_button(NULL), _play_button(NULL)
        , _figure(NULL), _room(NULL), _menu(NULL), _back(NULL), _changeFigure(NULL), _info(NULL)
        , _friends(NULL) {};

    void updateChatBoxPosition();

    //schedule update
    void update(float dt);

private:

    const cocos2d::Size kVisibleSize;

    //��¼��ǰ���������������������ϵĲ���
    static MainScene* _that;

    //�����汳��
    cocos2d::Sprite* _bg;

    //loading��
   LoadingScene* _loading;

   //�˵�
   cocos2d::ui::Button* _menu_button;

   //������Ϣ
   cocos2d::ui::Button* _info_button;

   //��ʼ��Ϸ��ť
   cocos2d::ui::Button* _play_button;

   //��������ʾ��������
   cocos2d::ui::Button* _figure;

   //�����
   RoomLayer* _room;

   //�˵���
   MenuLayer* _menu;

   //���ذ�ť
   cocos2d::ui::Button* _back;

   //ѡ���ɫ��
   FigureLayer* _changeFigure;

   //info��
   InforLayer* _info;

   //���Ѱ�ť
   cocos2d::ui::Button* _friends;

   //friend��
   FriendLayer* _friend;

   //��Ϣ��ť 
   cocos2d::ui::Button* _messages;

   //����򰴼�
   virtual bool onPressKey(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
   virtual bool onReleaseKey(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

   cocos2d::EventListenerKeyboard* _gmlistenerKeyBoard;

   //�����
   ChatBox* _chatBox;

   //��¼�������
   static int _countButton;
};
