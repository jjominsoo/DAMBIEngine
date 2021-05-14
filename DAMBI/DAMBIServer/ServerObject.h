#pragma once
class ServerObject
{
private:
	SOCKET Socket;
	HANDLE IoCompletionPort;
public:
	ServerObject();
	~ServerObject();
	bool CreateSocket(const std::string strBindIP, UINT Port);
	void CreateIocpPort();
	SOCKET GetSocket() { return Socket; };
	HANDLE GetIocpPort() { return IoCompletionPort; }
};

