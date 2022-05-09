#pragma once
#include "cocos2d.h"

//�����½ǣ�0,0����ʼ����Ƭ��ͼ
typedef std::vector<std::vector<bool>> TileVector;
const int maxWidth = 32 * 75;
const int maxHeight = 32 * 75;

//Tag
const int kBarrierTag = 0;
const int kBoxTag = 1;
//Priority
const int kBarrierPriority = 0;
const int kBoxPriority = 1;

//�ļ�·��
namespace Path 
{
	static const std::string BoxClose = "Box/BoxClose.png";
	static const std::string BoxOpen = "Box/BoxOpen.png";
}

namespace Name
{
	static const std::string kTreasure = "Treasure";
}
