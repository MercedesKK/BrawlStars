//2150266 ʱ����

#pragma once

#include "cocos2d.h"
#include "Hero/HeroSprite.h"
#include "Participant/ParticipantNode.hpp"

template<typename HeroType>
class Player :public Participant<HeroType>
{

};