#include "extern.h"
#include "stdafx.h"
#include "ClientObject.h"

void AcceptThread(SOCKET ServerSocket) {
	while (true) {

		ClientObject* cObject = NULL;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));


		SOCKET Socket;
		struct sockaddr_in ClientAddr;
		int ClientAddrSize = sizeof(ClientAddr);
		Socket = WSAAccept(ServerSocket, (struct sockaddr*)&ClientAddr, &ClientAddrSize, NULL, NULL);
		if (Socket == INVALID_SOCKET) {
		
			std::cout << "Accept Fail " << WSAGetLastError() << std::endl;
			continue;
		}
		cObject = new ClientObject;
		std::string strClientAddr;
		UINT ClientPort;
		strClientAddr = inet_ntoa(ClientAddr.sin_addr);
		ClientPort = ntohs(ClientAddr.sin_port);
		cObject->SetClientSocket(Socket);
		cObject->SetClientInfo(strClientAddr, ClientPort);
		cObject->SetRecvStatus();
		
	}
}

