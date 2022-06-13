#pragma once
#include"cocos2d.h"
#include"Socket.h"

/**
* @brief �ͻ��ˣ�������
*/
class Client :public cocos2d::Ref
{
public:

	//��һ����Ҫ��ip��ַ
	static Client* getInstance(const std::string& ip = "");

	//�ر��׽���
	void Close();

	//��ʼ��������
	void Start();

	//��ȡ��������
	virtual void update(std::vector<std::string>& data);

	//��������
	void sendData(const std::string&);

private:

	//��������
	void recvData();

	Client(const std::string& ip);

	//�����ͻ���socket
	static bool create(const std::string& ip);

private:

	//��Ϣ�б�
	std::vector<std::string> _msg;

	static SOCKET _socket;

	static Client* _client;

	std::mutex _mutex;

};

