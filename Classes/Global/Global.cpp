#include <vector>
#include "Const/Const.h"


//���Ӣ��
//��Ϸ����Ҫclear��
std::vector<HeroData> herodataVec;


//update leaderboard
void GameScene::updateLeaderBoard()
{
    static int overnum = 0;

    //��һ��������2����������over�Ľ���������+1
    //�ܳԼ������ж�over�����������10���Լ���+1

    //����
    if (!_heroVec[0]->alive())
    {
        ++overnum;
        if (overnum != 10)
        {
            single.insert(10, Rank{ 1 + overnum,0 });
            single.insert_sum(10, Rank{ 1 + overnum,0 });//�Լ���Ҳ���Զ������
        }
        //��һ��
        else
        {
            single.insert(10, Rank{ 1 + overnum,1 });
            single.insert_sum(10, Rank{ 1 + overnum,1 });
        }
    }

    //������/������ң�
    if (!_heroVec[1]->alive())
    {
        ++overnum;
        if (overnum != 10)
        {
            single.insert(11, Rank{ 1 + overnum,0 });
            single.insert_sum(11, Rank{ 1 + overnum,0 });
        }
        else
        {
            single.insert(11, Rank{ 1 + overnum,1 });
            single.insert_sum(11, Rank{ 1 + overnum,1 });
        }
    }
    else if (!_heroVec[2]->alive())
    {
        ++overnum;
        if (overnum != 10)
        {
            single.insert(12, Rank{ 1 + overnum,0 });
            single.insert_sum(12, Rank{ 1 + overnum,0 });
        }
        else
        {
            single.insert(12, Rank{ 1 + overnum,1 });
            single.insert_sum(12, Rank{ 1 + overnum,1 });
        }
    }
    else if (!_heroVec[3]->alive())
    {
        ++overnum;
        if (overnum != 10)
        {
            single.insert(13, Rank{ 1 + overnum,0 });
            single.insert_sum(13, Rank{ 1 + overnum,0 });
        }
        else
        {
            single.insert(13, Rank{ 1 + overnum,1 });
            single.insert_sum(13, Rank{ 1 + overnum,1 });
        }
    }
    else if (!_heroVec[4]->alive())
    {
        ++overnum;
        if (overnum != 10)
        {
            single.insert(14, Rank{ 1 + overnum,0 });
            single.insert_sum(14, Rank{ 1 + overnum,0 });
        }
        else
        {
            single.insert(14, Rank{ 1 + overnum,1 });
            single.insert_sum(14, Rank{ 1 + overnum,1 });
        }
    }
    else if (!_heroVec[5]->alive())
    {
        ++overnum;
        if (overnum != 10)
        {
            single.insert(15, Rank{ 1 + overnum,0 });
            single.insert_sum(15, Rank{ 1 + overnum,0 });
        }
        else
        {
            single.insert(15, Rank{ 1 + overnum,1 });
            single.insert_sum(15, Rank{ 1 + overnum,1 });
        }
    }
    else if (!_heroVec[6]->alive())
    {
        ++overnum;
        if (overnum != 10)
        {
            single.insert(16, Rank{ 1 + overnum,0 });
            single.insert_sum(16, Rank{ 1 + overnum,0 });
        }
        else
        {
            single.insert(16, Rank{ 1 + overnum,1 });
            single.insert_sum(16, Rank{ 1 + overnum,1 });
        }
    }
    else if (!_heroVec[7]->alive())
    {
        ++overnum;
        if (overnum != 10)
        {
            single.insert(17, Rank{ 1 + overnum,0 });
            single.insert_sum(17, Rank{ 1 + overnum,0 });
        }
        else
        {
            single.insert(17, Rank{ 1 + overnum,1 });
            single.insert_sum(17, Rank{ 1 + overnum,1 });
        }
    }
    else if (!_heroVec[8]->alive())
    {
        ++overnum;
        if (overnum != 10)
        {
            single.insert(18, Rank{ 1 + overnum,0 });
            single.insert_sum(18, Rank{ 1 + overnum,0 });
        }
        else
        {
            single.insert(18, Rank{ 1 + overnum,1 });
            single.insert_sum(18, Rank{ 1 + overnum,1 });
        }
    }
    else if (!_heroVec[9]->alive())
    {
        ++overnum;
        if (overnum != 10)
        {
            single.insert(19, Rank{ 1 + overnum,0 });
            single.insert_sum(19, Rank{ 1 + overnum,0 });
        }
        else
        {
            single.insert(19, Rank{ 1 + overnum,1 });
            single.insert_sum(19, Rank{ 1 + overnum,1 });
        }
    }

}