#include "extern.h"
#include "stdafx.h"
#include "MainConfig.h"
void LogThread()
{
	
	while (true) {
		Log.LogWrite();
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
		if (pMainConfig->getThreadEnd() && Log.isLogEmpty())
		{
			break;
		}
	}
}
