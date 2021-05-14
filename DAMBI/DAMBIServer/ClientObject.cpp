#include "stdafx.h"
#include "extern.h"
#include "ClientObject.h"
#include "ServerObject.h"
ClientObject::ClientObject()
{
}

ClientObject::~ClientObject()
{
}

void ClientObject::SetClientSocket(SOCKET ClientSocket)
{
	Socket = ClientSocket;
}

void ClientObject::SetClientInfo(const std::string Addr, const UINT Port)
{
	strClientAddr = Addr;
	ClientPort = Port;
}

void ClientObject::SetRecvStatus()
{
	BOOL bSockOpt = TRUE;
	setsockopt(Socket, IPPROTO_TCP, TCP_NODELAY, (char*)&bSockOpt, sizeof(bSockOpt));

	int nSockBufSize = 8192; 
	setsockopt(Socket, SOL_SOCKET, SO_SNDBUF, (const char*)&nSockBufSize, sizeof(nSockBufSize));

	// register IOCP Port
	if (CreateIoCompletionPort((HANDLE)Socket, pServerObject->GetIocpPort(), (ULONG_PTR)this, 0) == NULL)
	{
		std::cout << "CreateIoCompletionPort Fail" << WSAGetLastError() << std::endl;
		return;
	}
	DWORD dwBytes = 0, dwFlags = 0;
	
}

