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

    /*-----------------------------------------------������*/
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

    /**
    * @brief �Ƿ񲥷ű�����
    */
    bool isSound() { return _sound; }

    /*-----------------------------------------------��Ч*/
    /**
    * @brief ����ָ����Ч
    */
    void GoSoundEffect(std::string filename);

    /**
    * @brief ������Ч�Ƿ񲥷�
    */
    void SoundEffectSet(const bool set);

    /**
    * @brief ������Ч�ٷֱ�
    */
    void SoundEffectPercentSet(const int persent);

    /**
    * @brief �Ƿ񲥷���Ч
    */
    bool isSoundEffect() { return _sound_effect; }

private:

    static Setting* instance;

    bool _sound;

    bool _sound_effect;

    CocosDenshion::SimpleAudioEngine* _sound_engine = CocosDenshion::SimpleAudioEngine::getInstance();

private:

    Setting() :_sound(true), _sound_effect(true) {};

};

