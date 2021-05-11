#include "extern.h"
#include "stdafx.h"
#include "threads.h"
#include "ServerObject.h"

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
}

void InitThread()
{
	//Create LogicThread
	std::thread* Logic = new std::thread(LogicThread);
	//Create AcceptThread
	std::thread* Accpet = new std::thread(AcceptThread, pServerObject->GetSocket());
	//Create LogThread
	std::thread* Log = new std::thread(LogThread);

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
	char msg[] = "Server Start!";
	

	/*
	
	todo : init 함수 만들고 로그 작성하게끔 해주자. 콘솔로보면 눈알 아프니
	
	*/
	Init();
	InitQueue();
	InitThread();
	/*

	todo : main이 너무 더럽다. main은 스레드 관리만 하기에도 바쁜데. 너무 복잡해지면 생각 해보자

	*/
	LogQueue->push(msg);

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		// todo : thread가 다 끝났을때 프로그램이 종료되게 해주는것도 포함하고, ctrl + c 눌렀을때 종료하는 것도 해주자.
		// 당연히 ctrl + c 했을때 보내던거는 마저 보내고 데이터 처리하는 거는 처리할 꺼 다 처리하고 종료 시켜야 겠지? 타이밍 중요
	}

	std::cout << "Server Stop!" << std::endl;
	return 0;
}