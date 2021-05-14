#pragma once
class ClientObject
{
private:
	SOCKET Socket;
	std::string strClientAddr;
	UINT ClientPort;
	char* RecvBuffer;
public:
	ClientObject();
	~ClientObject();
	void SetClientSocket(SOCKET ClientSocket);
	void SetClientInfo(const std::string Addr, const UINT Port);
	void SetRecvStatus();
};

