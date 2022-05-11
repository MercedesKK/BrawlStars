#pragma once
#include "cocos2d.h"

//�����½ǣ�0,0����ʼ����Ƭ��ͼ
typedef std::vector<std::vector<bool>> TileVector;
const int maxWidth = 32 * 75;
const int maxHeight = 32 * 75;

//����
const int kmaxBoxHealthPoint = 3360;

//��������������Tag��Name��������ײ���ӿ�
//Tag
const int kBarrierTag = 0;
const int kBoxTag = 1;
const int kDiamondTag = 2;

//Buff��ֵ
const int kBuffAttack = 100;
const int kBuffHealth = 1000;

namespace Name
{
	static const std::string kBarrier = "Barrier";
	static const std::string kTreasureBox = "TreasureBox";
	static const std::string kDiamond = "Diamond";
}

//general Priority
const int kMapPriority = 0;
const int kHeroPriority = 1;
const int kBarrierPriority = 2;//�ϰ���������������ȼ�
const int kBoxPriority = 3;
const int kDiamondPriority = 4;

//global Priority �����Ǳ�general Priority�ߵģ���
const int kTMXlayer = 100;

//�ļ�·��
namespace Path
{
	static const std::string BoxClose = "Box/BoxClose.png";
	static const std::string BoxOpen = "Box/BoxOpen.png";
	static const std::string Diamond = "Box/diamond.png";

	static const std::string kbloodStrip = "bloodStrip.png";
}

