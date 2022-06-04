#pragma once
#include "cocos2d.h"
#include <vector>

/**
* @brief ��ɫ����
*/
struct HeroData
{
	std::string name_isRobot;
	std::string heroID;
	HeroData(std::string iname_isRobot, std::string heroID = "") :name_isRobot(iname_isRobot), heroID(heroID) {};
};
//��Ϸ����
const int playerNum = 10;

//�����½ǣ�0,0����ʼ����Ƭ��ͼ
typedef std::vector<std::vector<bool>> TileVector;
const int maxWidth = 32 * 75;
const int maxHeight = 32 * 75;



/**
* @brief Tagֵ
* ***
* @����ûд 10������ 11-19��������һ������
* @��ʹ��getChildByTag()
*/
namespace SceneTag
{
	const int kGameSceneTag = 1;
}




//��������������Tag��Name��������ײ���ӿ�
//Tag
const int kGrassTag = 0;
const int kBarrierTag = 1;
//const int kBoxTag = 1;/*delete!!!*/
//const int kDiamondTag = 2;/*delete!!!*/

namespace Name
{
	static const std::string kBarrier = "wall";
	//static const std::string kTreasureBox = "TreasureBox";
	//static const std::string kDiamond = "Diamond";
	static const std::string kGrass = "grass";
}

//general Priority
const int kMapPriority = 0;
const int kGrassPriority = 0;//�������棬�͵�ͼͬ�ȼ�
const int kHeroPriority = 1;
const int kBarrierPriority = 2;//�ϰ���������������ȼ�
const int kTimerPriority = 3;
//const int kpoisonPriority = 4;
//const int kBoxPriority = 3;/*delete!!!*/
//const int kDiamondPriority = 4;/*delete!!!*/

//global Priority �����Ǳ�general Priority�ߵģ���
const int kTMXlayer = 100;//�ϰ�ͼƬ�����ȼ�
const int kpoisonPriority = 101;//��Ȧ
const int kFightUI = 102;//ս��ʱ���UI

//�ļ�·��
namespace Path
{
	//map
	static const std::string map1 = "map/mapNo1.tmx";
	static const std::string map2 = "map/mapNo2.tmx";
	static const std::string map3 = "map/mapNo3.tmx";

	//UI
	static const std::string UITimer = "UI/SEUITime.png";

	//����ͼ
	static const std::string BoxClose = "Box/BoxClose.png";
	static const std::string BoxOpen = "Box/BoxOpen.png";
	static const std::string Diamond = "Box/diamond.png";

	static const std::string kbloodStrip = "bloodStrip.png";
}

