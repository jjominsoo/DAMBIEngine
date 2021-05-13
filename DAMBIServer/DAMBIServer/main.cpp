#include "extern.h"
#include "stdafx.h"
#include "threads.h"
#include "ServerObject.h"

std::thread* Logic;
std::thread* Accept;
std::thread* Log;

void Init()
{
	pServerObject = new ServerObject;
	WSADATA WsaData;
	WSAStartup(MAKEWORD(2, 2), &WsaData);
	
	if (pServerObject->CreateSocket("127.0.0.1", 3587))
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
	//Create LogicThread
	//Logic = new std::thread(LogicThread);
	//Create AcceptThread
	//Accept = new std::thread(AcceptThread, pServerObject->GetSocket());
	//Create LogThread
	Log = new std::thread(LogThread);
	
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
	Init();
	InitQueue();
	InitThread();

	LOG_INFO("Server Start!");
	int eventListener = 0;

	while (true)
	{
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
		eventListener = _getch();
		if (eventListener == 3)
		{
			ThreadEnd = 1;
			break;
		}
	}

	LOG_INFO("Server End!");
	LOG_INFO("Bye Bye");

	Accept->join();
	Logic->join();
	Log->join();
	
	return 0;
}