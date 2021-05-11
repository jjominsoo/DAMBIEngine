#include "extern.h"
#include "stdafx.h"

void LogThread()
{
	std::ofstream out("Log.txt");
	while (true) {
		logger.mtx.lock();
		if (!LogQueue->empty())
		{
			char* msg = LogQueue->front();
			LogQueue->pop();
			out << msg << std::endl;

		}
		logger.mtx.unlock();
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	// todo : ¹Ú¹Î±â ÆÄÀÏ ´Ý´Â°Å °´Ã¼·Î ¸¸µé¾î ÁÖÀÚ. Logger.end();
}

