#pragma once

#include "cocos2d.h"
#include"ui/CocosGUI.h"

class HeroFactory;
class MainScene;

/**
* @brief ��ʼ�ĵ�¼����,ʵ���ϼ̳���LayerȻ������main������
*/
class FigureLayer : public cocos2d::Layer
{
public:

    CREATE_FUNC(FigureLayer);

private:

    /**
    * @brief ������¼�����棬ͬ������������������
    */
    virtual bool init();

    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*) { return true; }

    //���ﲻ�ܸ�std::string����ָ�룬�ݿ�������,NULL��ϰ���ˣ�Ӧ����ʹ���˿�ָ��ϵͳ���������string�ж೤��
    FigureLayer() :kVisibleSize(cocos2d::Director::getInstance()->getVisibleSize())
        ,  _bg(NULL), _back(NULL), _figure(""), _select(NULL) 
    {
    };

    /**
    * @brief ��ʾ���н�ɫ
    */
    void SetFigures();

private:

    //����Ӣ������
    static std::vector<std::string> heroVec;

    const cocos2d::Size kVisibleSize;

    //���н�ɫ����,�ڳ�ʼ���ĵط�����ֵ���൱��#define
    int kNum;

    //����
    cocos2d::Sprite* _bg;

    //���ذ�ť
    cocos2d::ui::Button* _back;

    //��������
    cocos2d::Vector<cocos2d::ui::Button*> _figures;

    //��ǰ����
    std::string _figure;

    //��¼select��־
    cocos2d::Sprite* _select;

};

