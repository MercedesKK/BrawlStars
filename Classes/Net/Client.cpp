#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Client.h"
#include"Tool/Data.h"
using namespace std;

SOCKET Client::_socket = INVALID_SOCKET;
Client* Client::_client = NULL;
static std::mutex _mutex;

Client* Client::getInstance(const std::string& ip)
{
	if (_client == NULL)
	{
		
		if (ip != "")
		{
			_client = new Client(ip);
			//�ݴ���
			if (_client)
			{
				_client->autorelease();
				_client->retain();
			}
			else
			{
				CC_SAFE_DELETE(_client);
				_client = NULL;
			}
		}
	}

	if (_socket == INVALID_SOCKET)
		return NULL;
	return _client;
}

void Client::Close()
{
	if (_socket != INVALID_SOCKET && _client != NULL)
	{
		_socket = INVALID_SOCKET;
		delete _client;
		_client = NULL;
		closesocket(_socket);
	}
}

void Client::recvData()
{
	while (true)
	{
		char recvBuf[kMAX] = "";
		int ret = recv(_socket, recvBuf, kMAX, 0);
		if (ret <= 0)
			break;
		//��������������
		{
			CCLOG("recieve true");
			std::lock_guard<std::mutex>lock(_mutex);
			if (recvBuf[0] == '?' && recvBuf[1] == 'F' && recvBuf[2] == 'R')
				Client::getInstance()->sendData("FRI" + PlistData::getDataByType(PlistData::DataType::Profile)
					+ ":" + PlistData::getDataByType(PlistData::DataType::Name)
					+ ":" + PlistData::getDataByType(PlistData::DataType::Cups)
					+ ":" + PlistData::getDataByType(PlistData::DataType::ID));
			else
				_msg.push_back(recvBuf);
		}
		Sleep(20);
	}
	CCLOG("server down");
	Close();
	Socket::close_Socket();
}

void Client::sendData(const std::string& data)
{
	if (INVALID_SOCKET == send(_socket, data.c_str(), kMAX, 0))//���һ����flagд0����
		err("send");
}

void Client::updateFriend(std::vector<std::string>& data)
{
	//������
	std::lock_guard<std::mutex>lock(_mutex);

	std::vector<std::string>::iterator it = _msg.begin();
	while (it != _msg.end())
	{
		auto poi = (*it).substr(0, 3);
		if (poi == "FRI")
		{
			auto value = (*it).substr(3);
			data.push_back(value);
			it = _msg.erase(it);
			if (it == _msg.end())
				break;
		}
		++it;
	}
}

void Client::Start()
{
	std::thread recvThread = std::thread(&Client::recvData, this);
	recvThread.detach();
}

void Client::update(std::vector<std::string>& data)
{
	//������
	std::lock_guard<std::mutex>lock(_mutex);


	std::vector<std::string>::iterator it = _msg.begin();
	while (it != _msg.end())
	{
		auto poi = (*it).substr(0, 3);
		if (poi == "MSG")
		{
			data.push_back(*it);
			it = _msg.erase(it);
			if (it == _msg.end())
				break;
		}
		++it;
	}

	/*for (auto value : _msg)
	{
		data.push_back(value);
		CCLOG(value.c_str());
	}
	_msg.clear();*/
}

Client::Client(const std::string& ip)
{
	if (_socket == INVALID_SOCKET && ip != "")
	{
		if (!create(ip))
			err("create server");
	}
}

bool Client::create(const std::string& ip)
{
	//1 ����һ���յ�socket
	SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//AF_INET����ipv4(Э����),SOCK_STREAMΪ��ʽ�׽���,IPPROTO_TCP TCPЭ��)
	if (INVALID_SOCKET == client)//�޷�����ȡ�����޷���int���
	{
		err("socket");
		return false;
	}

	//2 ��socket�󶨷���˵�ip�Ͷ˿�
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;//Э����
	addr.sin_port = htons(kPORT);//�˿ں�(htons��Ϊ�����ֽ���,��˴洢С�˴洢)
	addr.sin_addr.S_un.S_addr = inet_addr(ip.c_str());

	int retry_times = 0;
	while (INVALID_SOCKET == connect(client, static_cast<struct sockaddr*>(static_cast<void*>(&addr)), sizeof(addr)) && retry_times < 3)
	{
		++retry_times;
		err("retry connect");
	    
		//��һ��������
		Sleep(300);
		if (retry_times == 3)
		{
			err("connect fail");
			return false;
		}
	}

	CCLOG("connect true");
	_socket = client;
	return true;
}
