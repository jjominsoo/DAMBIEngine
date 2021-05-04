#include "extern.h"
#include "stdafx.h"

void Logicthread() {
	while (true) {
	
		if (!LogicQueue->empty())
		{
			int data = LogicQueue->front();
			LogicQueue->pop();
			std::cout << data;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

