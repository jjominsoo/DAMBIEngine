#include "extern.h"
#include "stdafx.h"
#include "MainConfig.h"
void LogicThread() {
	while (true) {
	
		if (!LogicQueue->empty())
		{
			int data = LogicQueue->front();
			LogicQueue->pop();
			std::cout << data;
		}
		if (pMainConfig->getThreadEnd())
			break;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));

	}
}

