#include"Server.h"
using namespace std;

int main()
{
	string ip;
	cout << "����������ip" << endl;
	cin >> ip;
	Socket::init_Socket();
	Server::getInstance(ip)->Start();
	Server::getInstance()->Doit();
	//Server::getInstance()->recvData();
	//std::thread recvThread = std::thread(Server::getInstance()->recvData());
	//recvThread.detach();
	cout << "��Ҫ������������Ϣ���밴�ո�ʽ���ͣ���Ҫ�˳���������ESC\n";
	while (true)
	{
		char a[kMAX];
		cin.getline(a, kMAX, '\n');
		
		if (a[0] == 'E' && a[1] == 'S' && a[2] == 'C')
			break;
		Server::getInstance()->sendData(a);
	}

	Server::getInstance()->Close();
	std::cout << "Server close\n";
	Socket::close_Socket();
}