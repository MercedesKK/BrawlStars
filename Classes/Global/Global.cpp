#include <vector>
#include "Const/Const.h"
#include"Tool/LeaderBoard.hpp"
#include"View/GameScene.h"

//û���԰�

std::vector<HeroData> herodataVec;

LeaderBoard<std::string, Rank> single;

LeaderBoard<std::string, Rank> all;

////update leaderboard
//void GameScene::updateLeaderBoard()
//{
//    static int overnum = 0;
//
//    //��һ��������2����������over�Ľ���������+1
//    //�ܳԼ������ж�over�����������10���Լ���+1
//
//    //����
//    if (!_heroVec[0]->alive())
//    {
//        ++overnum;
//        if (overnum != 10)
//        {
//            single.insert("hero", Rank{ 1 + overnum,0 });
//            //single.insert("hero", Rank{ 1,0 });
//            all.insert_sum("hero", Rank{ 1 + overnum,0 });
//
//        }
//        //��һ��
//        else
//        {
//            single.insert("hero", Rank{ 1 + overnum,1 });
//            // single.insert("hero", Rank{ 1,0 });
//            all.insert_sum("hero", Rank{ 1 + overnum,1 });
//        }
//    }
//
//    //������/������ң�
//    if (!_heroVec[1]->alive())
//    {
//        ++overnum;
//        if (overnum != 10)
//        {
//            single.insert("hero", Rank{ 1 + overnum,0 });
//            all.insert_sum("hero", Rank{ 1 + overnum,0 });
//        }
//        else
//        {
//            single.insert("hero", Rank{ 1 + overnum,1 });
//            all.insert_sum("hero", Rank{ 1 + overnum,1 });
//        }
//    }
//    else if (!_heroVec[2]->alive())
//    {
//        ++overnum;
//        if (overnum != 10)
//        {
//            single.insert("hero", Rank{ 1 + overnum,0 });
//            all.insert_sum("hero", Rank{ 1 + overnum,0 });
//        }
//        else
//        {
//            single.insert("hero", Rank{ 1 + overnum,1 });
//            all.insert_sum("hero", Rank{ 1 + overnum,1 });
//        }
//    }
//    else if (!_heroVec[3]->alive())
//    {
//        ++overnum;
//        if (overnum != 10)
//        {
//            single.insert("hero", Rank{ 1 + overnum,0 });
//            all.insert_sum("hero", Rank{ 1 + overnum,0 });
//        }
//        else
//        {
//            single.insert("hero", Rank{ 1 + overnum,1 });
//            all.insert_sum("hero", Rank{ 1 + overnum,1 });
//        }
//    }
//    else if (!_heroVec[4]->alive())
//    {
//        ++overnum;
//        if (overnum != 10)
//        {
//            single.insert("hero", Rank{ 1 + overnum,0 });
//            all.insert_sum("hero", Rank{ 1 + overnum,0 });
//        }
//        else
//        {
//            single.insert("hero", Rank{ 1 + overnum,1 });
//            all.insert_sum("hero", Rank{ 1 + overnum,1 });
//        }
//    }
//    else if (!_heroVec[5]->alive())
//    {
//        ++overnum;
//        if (overnum != 10)
//        {
//            single.insert("hero", Rank{ 1 + overnum,0 });
//            all.insert_sum("hero", Rank{ 1 + overnum,0 });
//        }
//        else
//        {
//            single.insert("hero", Rank{ 1 + overnum,1 });
//            all.insert_sum("hero", Rank{ 1 + overnum,1 });
//        }
//    }
//    else if (!_heroVec[6]->alive())
//    {
//        ++overnum;
//        if (overnum != 10)
//        {
//            single.insert("hero", Rank{ 1 + overnum,0 });
//            all.insert_sum("hero", Rank{ 1 + overnum,0 });
//        }
//        else
//        {
//            single.insert("hero", Rank{ 1 + overnum,1 });
//            all.insert_sum("hero", Rank{ 1 + overnum,1 });
//        }
//    }
//    else if (!_heroVec[7]->alive())
//    {
//        ++overnum;
//        if (overnum != 10)
//        {
//            single.insert("hero", Rank{ 1 + overnum,0 });
//            all.insert_sum("hero", Rank{ 1 + overnum,0 });
//        }
//        else
//        {
//            single.insert("hero", Rank{ 1 + overnum,1 });
//            all.insert_sum("hero", Rank{ 1 + overnum,1 });
//        }
//    }
//    else if (!_heroVec[8]->alive())
//    {
//        ++overnum;
//        if (overnum != 10)
//        {
//            single.insert("hero", Rank{ 1 + overnum,0 });
//            all.insert_sum("hero", Rank{ 1 + overnum,0 });
//        }
//        else
//        {
//            single.insert("hero", Rank{ 1 + overnum,1 });
//            all.insert_sum("hero", Rank{ 1 + overnum,1 });
//        }
//    }
//    else if (!_heroVec[9]->alive())
//    {
//        ++overnum;
//        if (overnum != 10)
//        {
//            single.insert("hero", Rank{ 1 + overnum,0 });
//            all.insert_sum("hero", Rank{ 1 + overnum,0 });
//        }
//        else
//        {
//            single.insert("hero", Rank{ 1 + overnum,1 });
//            all.insert_sum("hero", Rank{ 1 + overnum,1 });
//        }
//    }
//
//
//
//}

