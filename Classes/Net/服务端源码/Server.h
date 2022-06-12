#pragma once
#include"Socket.h"
#include<vector>
#include<mutex>
#include<iostream>
#include<memory.h>

/**
* @brief ����ˣ�������
*/
class Server
{
public:

	static std::shared_ptr<Server>& getInstance(const std::string& ip = "");

	//�ر��׽���
	void Close();

	//��ʼ���տͻ���
	void Start();

	//��������
	void recvData();

	//�����߳̽�����Ϣ
	void Doit()
	{
		std::thread recvThread = std::thread(&Server::recvData, this);
		recvThread.detach();
	}

	//��������
	void sendData(const char*);


private:

	Server(const std::string& ip);

	//���ܿͻ���
	void Accept();

	//���������socket
	static bool create(const std::string& ip);

	//����data����
	void Do();

private:

	static SOCKET _socket;

	/*static Server* _server;*/

	static std::shared_ptr<Server> _server;

	char _data[kMAX];

	//�ͻ��˼���
	std::vector<SOCKET> _client;

};


