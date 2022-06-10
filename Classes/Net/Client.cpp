#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Client.h"

SOCKET Client::_socket = INVALID_SOCKET;
Client* Client::_client = NULL;

Client* Client::getInstance(const std::string& ip)
{
	if (_client == NULL)
	{
		
		if (ip != "")
		{
			_client = new Client(ip);
			//容错处理
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
	if (_socket != INVALID_SOCKET)
		closesocket(_socket);
}

void Client::recvData()
{
	while (true)
	{
		char recvBuf[kMAX] = "";
		int ret = recv(_socket, recvBuf, kMAX, 0);
		if (ret <= 0)
			break;
		//给锁定下作用域
		{
			CCLOG("recieve");
			std::lock_guard<std::mutex>lock(_mutex);
			_msg.push_back(recvBuf);
		}
		Sleep(20);
	}
	CCLOG("client down");
}

void Client::sendData(const std::string& data)
{
	if (INVALID_SOCKET == send(_socket, data.c_str(), kMAX, 0))//最后一个是flag写0即可
		err("send");
}

void Client::Start()
{
	std::thread recvThread = std::thread(&Client::recvData, this);
	recvThread.detach();
}

void Client::update(std::vector<std::string>& data)
{
	//智能锁
	std::lock_guard<std::mutex>lock(_mutex);

	for (auto value : _msg)
	{
		data.push_back(value);
		CCLOG(value.c_str());
	}
	_msg.clear();
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
	//1 创建一个空的socket
	SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//AF_INET代表ipv4(协议族),SOCK_STREAM为流式套接字,IPPROTO_TCP TCP协议)
	if (INVALID_SOCKET == client)//无符号零取反，无符号int最大
	{
		err("socket");
		return false;
	}

	//2 给socket绑定服务端的ip和端口
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;//协议族
	addr.sin_port = htons(kPORT);//端口号(htons变为网络字节序,大端存储小端存储)
	addr.sin_addr.S_un.S_addr = inet_addr(ip.c_str());

	int retry_times = 0;
	while (INVALID_SOCKET == connect(client, static_cast<struct sockaddr*>(static_cast<void*>(&addr)), sizeof(addr)) && retry_times < 7)
	{
		++retry_times;
		err("retry connect");
	    
		//等一会再重连
		Sleep(500);
	}
	if (retry_times == 7)
	{
		err("connect fail");
		return false;
	}

	CCLOG("connect true");
	_socket = client;
	return true;
}
