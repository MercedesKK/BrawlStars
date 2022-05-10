#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "editor-support/cocostudio/SimpleAudioEngine.h"

/**
* @brief ���ÿ�����
*/
class Setting :public cocos2d::Ref
{
public:

    static Setting* getInstance();

    /**
    * @brief ����ָ����������
    */
    void GoSound(std::string filename);

    /**
    * @brief ���ñ��������Ƿ񲥷�
    */
    void SoundSet(const bool set);

    /**
    * @brief ֹͣ��ǰ������
    */
    void StopSound();

    /**
    * @brief ���ñ��������ٷֱ�
    */
    void SoundPercentSet(const int persent);

private:

    static Setting* instance;

    bool _sound;

    CocosDenshion::SimpleAudioEngine* _sound_engine = CocosDenshion::SimpleAudioEngine::getInstance();

private:

    Setting() :_sound(true) {};

};

