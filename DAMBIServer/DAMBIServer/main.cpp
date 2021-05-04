#include "extern.h"
#include "stdafx.h"
#include "threads.h"

void InitQueue() 
{
	LogicQueue =  new std::queue<int>;
}
void InitThread()
{
	std::thread* Logic = new std::thread(Logicthread);

}
int main()
{
	std::cout << "Server Start!" << std::endl;

	/*
	
	todo : init 함수 만들고 로그 작성하게끔 해주자. 콘솔로보면 눈알 아프니
	
	*/
	InitQueue();
	InitThread();

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		// todo : thread가 다 끝났을때 프로그램이 종료되게 해주는것도 포함하고, ctrl + c 눌렀을때 종료하는 것도 해주자.
		// 당연히 ctrl + c 했을때 보내던거는 마저 보내고 데이터 처리하는 거는 처리할 꺼 다 처리하고 종료 시켜야 겠지? 타이밍 중요
	}

	std::cout << "Server Stop!" << std::endl;
	return 0;
}