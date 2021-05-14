#include "extern.h"
#include "stdafx.h"
#include "threads.h"
#include "ServerObject.h"
#include "MainConfig.h"
#include "windows.h"

void Init()
{
	pMainConfig = new MainConfig;
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
	LogicQueue = new std::queue<int>;
}

void InitThread()
{
	//Create LogicThread
	std::thread* pthread;
	pthread = new std::thread(LogicThread);
	pMainConfig->ThreadList.push_back(pthread);
	//Create AcceptThread
	pthread = new std::thread(AcceptThread, pServerObject->GetSocket());
	pMainConfig->ThreadList.push_back(pthread);
	//Create LogThread
	pthread = new std::thread(LogThread);
	pMainConfig->ThreadList.push_back(pthread);

	//Create WorkerThread
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);

	std::thread* Worker;
	for (int i = 0; i < sysinfo.dwNumberOfProcessors; i++)
	{
		Worker = new std::thread(WorkerThread, pServerObject->GetIocpPort());
	}

}
BOOL WINAPI CtrlHandler(DWORD signal) {

	if (signal == CTRL_C_EVENT)
	{
		LOG_INFO("Server End!");
		LOG_INFO("Bye Bye");
		pMainConfig->setThreadEnd();
	}
	return TRUE;
}
int main()
{
	Init();
	InitQueue();
	InitThread();

	LOG_INFO("Server Start!");
	if (SetConsoleCtrlHandler(CtrlHandler, TRUE))
	{
		while (!pMainConfig->getThreadEnd())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}

	for (auto pthread : pMainConfig->ThreadList)
	{
		pthread->join();
	}

	return 0;
}