#include "extern.h"
#include "stdafx.h"

void LogThread()
{
	std::ofstream out("Log.txt");
	int logEnd = 0;
	
	while (true) {
		logger.mtx.lock();
		if (!LogQueue->empty())
		{
			char* msg = LogQueue->front();
			LogQueue->pop();
			out << msg << std::endl;
			free(msg);
		}
		logger.mtx.unlock();
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
		if (ThreadEnd)
		{
			LOG_INFO("LOG THREAD END!");
			logEnd = 1;
		}
		if (logEnd && LogQueue->empty())
			break;
	}
}
