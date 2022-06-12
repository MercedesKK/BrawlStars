#pragma warning(disable:4996)
#include "Server.h"

SOCKET Server::_socket = INVALID_SOCKET;
std::shared_ptr<Server> Server::_server = NULL;
static std::mutex _mutex;
using namespace std;

std::shared_ptr<Server>& Server::getInstance(const string& ip)
{
	if (_server == NULL)
	{
		if (ip != "")
		{
			std::shared_ptr<Server> p1(new Server(ip));
			_server = p1;
		}
	}
	return _server;
}

void Server::Close()
{
	if (_socket != INVALID_SOCKET || _server != NULL)
	{
		closesocket(_socket);
		_socket = INVALID_SOCKET;
		_server.reset();
		_server = NULL;
	}
}

void Server::Start()
{
	cout << "wait for accept" << endl;
	std::thread recvThread = std::thread(&Server::Accept, this);
	recvThread.detach();
}

void Server::recvData()
{
	while (_client.size() == 0);
	while (true)
	{
		for (auto item : _client)
		{
			int ret = recv(item, _data, kMAX, 0);
			if (ret <= 0)
				continue;
			Do();
		}
	}
}

void Server::sendData(const char*data)
{
	std::lock_guard<std::mutex>lock(_mutex);
	//��ȫ���ͻ��˷�
	
	vector<SOCKET>::iterator it = _client.begin();
	while (it != _client.end())
	{
		auto client = *it;
		if (INVALID_SOCKET == send(client, data, kMAX, 0))//���һ����flagд0����
		{
			cerr << "send fail" << __LINE__ << endl;
			it = _client.erase(it);
			cerr << "delete socket" << __LINE__ << endl;
			if (it != _client.end())
				continue;
		}
		cout << "sent " << data << " suc\n";
		++it;
	}
}

void Server::Accept()
{
	while (true)
	{
		SOCKET client = accept(_socket, NULL, NULL);
		cout << "one accept suc\n";
		//�������ķ�Χ
		{
			std::lock_guard<std::mutex>lock(_mutex);
			if (client != INVALID_SOCKET)
				_client.push_back(client);
			else
				cerr << "accept fail" << __LINE__ << endl;
		}
		sendData("MSG 520 hello");
		Sleep(50);
	}
}

Server::Server(const std::string& ip)
{
	if (_socket == INVALID_SOCKET)
	{
		if (!create(ip))
			cerr << "create server fail" << __LINE__ << endl;
	}
}

bool Server::create(const std::string& ip)
{

	//1 ����һ���յ�socket
	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//AF_INET����ipv4(Э����),SOCK_STREAMΪ��ʽ�׽���,IPPROTO_TCP TCPЭ��)
	if (INVALID_SOCKET == server)//�޷�����ȡ�����޷���int���
	{
		cerr << "socket fail" << __LINE__ << endl;
		return false;
	}

	//2 ��socket��ip�Ͷ˿�
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;//Э����
	addr.sin_port = htons(kPORT);//�˿ں�(htons��Ϊ�����ֽ���,��˴洢С�˴洢)
	addr.sin_addr.S_un.S_addr = inet_addr(ip.c_str());//ADDR_ANY;//�󶨱�������ip
	if (SOCKET_ERROR == bind(server, static_cast<struct sockaddr*>(static_cast<void*>(&addr)), sizeof(addr)))//ֱ��static_cast���а��������������,֮�����о���
	{
		cerr << "bind fail" << __LINE__ << endl;
		return false;
	}

	//3 ��ʼ����
	listen(server, 10);//10���д��������Ǹ�log

	_socket = server;
	return true;
}

void Server::Do()
{
	/*auto data = _data).asString();
	auto datatype = data.substr(0, data.find(':'));*/
	//data = data.substr(data.find(':') + 1);
	//if (datatype == "MEG")
	sendData(_data);
}

