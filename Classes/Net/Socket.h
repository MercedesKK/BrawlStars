#pragma once
#include<WinSock2.h>
#include <WS2tcpip.h>
#include"cocos2d.h"
#pragma comment(lib,"ws2_32.lib")

//�궨��һ��err����ʾ����
#define err(errMsg) CCLOG(cocos2d::Value(__LINE__).asString().c_str());\
CCLOG(errMsg);

//ʹ�ö˿�
constexpr int kPORT = 7777;
//��������С
constexpr int kMAX = 100;

/**
* @brief ���ڳ�ʼ���͹ر������
*/
class Socket
{
public:
	//��ʼ�������
	static bool init_Socket();

	//�ر������
	static bool close_Socket();

};

