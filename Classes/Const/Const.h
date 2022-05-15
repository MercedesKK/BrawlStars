#pragma once
#include "cocos2d.h"

//从左下角（0,0）开始的瓦片地图
typedef std::vector<std::vector<bool>> TileVector;
const int maxWidth = 32 * 75;
const int maxHeight = 32 * 75;

namespace SceneTag
{
	const int kGameSceneTag = 1;
}

//物理引擎设置了Tag和Name，方便碰撞检测接口
//Tag
const int kGrassTag = 0;
const int kBarrierTag = 1;
//const int kBoxTag = 1;/*delete!!!*/
//const int kDiamondTag = 2;/*delete!!!*/

namespace Name
{
	static const std::string kBarrier = "Barrier";
	//static const std::string kTreasureBox = "TreasureBox";
	//static const std::string kDiamond = "Diamond";
	static const std::string kGrass = "grass";
}

//general Priority
const int kMapPriority = 0;
const int kGrassPriority = 0;//物理引擎，和地图同等级
const int kHeroPriority = 1;
const int kBarrierPriority = 2;//障碍物物理引擎的优先级
const int kTimerPriority = 3;
//const int kBoxPriority = 3;/*delete!!!*/
//const int kDiamondPriority = 4;/*delete!!!*/

//global Priority （总是比general Priority高的！）
const int kTMXlayer = 100;//障碍图片的优先级
const int kFightUI = 101;//战斗时候的UI

//文件路径
namespace Path
{
	//map
	static const std::string map1 = "map/mapNo1.tmx";
	static const std::string map2 = "map/mapNo2.tmx";
	static const std::string map3 = "map/mapNo3.tmx";

	//UI
	static const std::string UITimer = "UI/SEUITime.png";

	//宝箱图
	static const std::string BoxClose = "Box/BoxClose.png";
	static const std::string BoxOpen = "Box/BoxOpen.png";
	static const std::string Diamond = "Box/diamond.png";

	static const std::string kbloodStrip = "bloodStrip.png";
}

