#include "stdafx.h"
#include "ServerObject.h"
#pragma comment(lib,"ws2_32.lib")
ServerObject::ServerObject()
{
	Socket = INVALID_SOCKET;
}

ServerObject::~ServerObject()
{
	Socket = INVALID_SOCKET;
}
bool ServerObject::CreateSocket(const std::string strBindIP, UINT Port)
{

	int nBindRet = 0;
	Socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (Socket == INVALID_SOCKET)
	{
		std::cout << "WSASocket Create Fail " << WSAGetLastError() <<std::endl;
		return false;
	}
	
	SOCKADDR_IN sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(Port);
	sin.sin_addr.s_addr = inet_addr(strBindIP.c_str());

	nBindRet = bind(Socket, (LPSOCKADDR)&sin, sizeof(sin));

	if (nBindRet == SOCKET_ERROR)
	{
		std::cout << "Bind Fail " << WSAGetLastError() << std::endl;
		return false;
	}

	if (listen(Socket, SOMAXCONN) == SOCKET_ERROR)
	{
		std::cout << "Listen Fail " << WSAGetLastError() << std::endl;
		//ClearSocket();
		return false;
	}
	
	return true;
}
void ServerObject::CreateIocpPort()
{
	IoCompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
}