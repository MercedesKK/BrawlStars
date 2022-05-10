#pragma once

#include "cocos2d.h"
#include"ui/CocosGUI.h"

class LoadingScene;
class RoomLayer;
class SettingLayer;

   /**
   * @brief ������
   */
class MainScene : public cocos2d::Scene
{
public:

    CREATE_FUNC(MainScene);

private:

    virtual bool init();

    //����

    //**
    //* @brief ���ð�ť��add������,���������ذ汾
    //* @param (Vec2 position)λ��
    //* @param (std::string pic_name)ͼƬ·��
    //* @param (std::string words)���ְ�ť����ʾ����
    //*/
    //cocos2d::ui::Button* ButtonCreate(const cocos2d::Vec2&& position, const std::string&& pic_name);
    //cocos2d::ui::Button* ButtonCreate(const std::string&& words,const cocos2d::Vec2&& position);

    MainScene() :kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize())
        , _bg(NULL), _loading(NULL), _menu_button(NULL), _info_button(NULL), _play_button(NULL)
        , _figure(NULL), _room(NULL), _set(NULL), _back(NULL) {};

private:

    const cocos2d::Size kVisibleSize;

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
   cocos2d::Sprite* _figure;

   //�����
   RoomLayer* _room;

   //���ò�
   SettingLayer* _set;

   //���ذ�ť
   cocos2d::ui::Button* _back;

};

