#include "extern.h"
#include "stdafx.h"
#include "MainConfig.h"
void WorkerThread(HANDLE hIOCP) {
	while (true) {

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		if (pMainConfig->getThreadEnd())
			break;
	}
}

