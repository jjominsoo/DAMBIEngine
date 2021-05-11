#include "extern.h"
#include "stdafx.h"
#include "threads.h"
#include "ServerObject.h"

void Init()
{
	pServerObject = new ServerObject;
	WSADATA WsaData;
	WSAStartup(MAKEWORD(2, 2), &WsaData);
	
	if (!pServerObject->CreateSocket("127.0.0.1", 3587))
	{
		std::cout << "Create Server Socket Error" << std::endl;
		return;
	}
	pServerObject->CreateIocpPort();
	
	
}
void InitQueue() 
{
	LogicQueue =  new std::queue<int>;
	LogQueue = new std::queue<char*>;
}

void InitThread()
{
	//Create LogThread
	std::thread* Log = new std::thread(LogThread);
	//Create LogicThread
	std::thread* Logic = new std::thread(LogicThread);
	//Create AcceptThread
	std::thread* Accpet = new std::thread(AcceptThread, pServerObject->GetSocket());

	//Create WorkerThread
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);

	std::vector<HANDLE> WorkerThreadList;
	std::thread* Worker;
	for (int i = 0; i < sysinfo.dwNumberOfProcessors; i++)
	{
		Worker = new std::thread(WorkerThread, pServerObject->GetIocpPort());
	}

}

int main()
{
	
	/*
	
	todo : init �Լ� ����� �α� �ۼ��ϰԲ� ������. �ַܼκ��� ���� ������
	
	*/

	Init();
	InitQueue();
	InitThread();
	/*

	todo : main�� �ʹ� ������. main�� ������ ������ �ϱ⿡�� �ٻ۵�. �ʹ� ���������� ���� �غ���

	*/
	//LogQueue->push(msg);
	//logger.writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_FATAL, "sdsd");
	
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		// todo : thread�� �� �������� ���α׷��� ����ǰ� ���ִ°͵� �����ϰ�, ctrl + c �������� �����ϴ� �͵� ������.
		// �翬�� ctrl + c ������ �������Ŵ� ���� ������ ������ ó���ϴ� �Ŵ� ó���� �� �� ó���ϰ� ���� ���Ѿ� ����? Ÿ�̹� �߿�
	}

	std::cout << "Server Stop!" << std::endl;
	return 0;
}