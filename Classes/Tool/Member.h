#pragma once

/**
* @brief ��ս��Ա��Ŀ�͹���(�����˵���Ŀ�����˵���Ŀ��
*/
class Member
{
public:

	/**
	* @brief �纯����������
	* @param 1Ϊ���һ�� 0Ϊɾ��һ��
	*/
	bool setRobot(bool is_plus);

	bool setHuman(bool is_plus);

	int getHuman() const { return _human; }

	int getRobot() const { return _robot; }

    //���з���һ��human
	Member() :_robot(0), _human(1) {};

private:

	int _robot;

	int _human;

};
