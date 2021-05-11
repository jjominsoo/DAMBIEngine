#include "extern.h"
#include "stdafx.h"

void WorkerThread(HANDLE hIOCP) {
	while (true) {

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

