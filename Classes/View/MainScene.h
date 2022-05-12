#pragma once

#include "cocos2d.h"
#include"ui/CocosGUI.h"

class LoadingScene;
class RoomLayer;
class SettingLayer;
class FigureLayer;
class InforLayer;

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

private:

    virtual bool init();

    MainScene() :kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize())
        , _bg(NULL), _loading(NULL), _menu_button(NULL), _info_button(NULL), _play_button(NULL)
        , _figure(NULL), _room(NULL), _set(NULL), _back(NULL), _changeFigure(NULL), _info(NULL) {};

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

   //���ò�
   SettingLayer* _set;

   //���ذ�ť
   cocos2d::ui::Button* _back;

   //ѡ���ɫ��
   FigureLayer* _changeFigure;

   //info��
   InforLayer* _info;

};

