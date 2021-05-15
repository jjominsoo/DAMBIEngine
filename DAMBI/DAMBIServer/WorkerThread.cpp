#include "extern.h"
#include "stdafx.h"
#include "MainConfig.h"
#include "ClientObject.h"
typedef struct message {
	int number;
	int age;
	char packet[10];
}message;
void WorkerThread(HANDLE hIOCP) {

	HANDLE IoCompletionPort = (HANDLE)hIOCP;
	SOCKET sock;
	DWORD  bytesTrans;
	DWORD flags = 0;
	OVERLAPPED_ENTRY entry;
	bool bResult = false;
	memset(&entry, 0, sizeof(entry));
	HMODULE hModule = ::GetModuleHandle(L"kernel32.dll");
	while (true) {
		bResult = GetQueuedCompletionStatus(IoCompletionPort, &entry.dwNumberOfBytesTransferred, &entry.lpCompletionKey, &entry.lpOverlapped, INFINITE);
		int a;
		if (bResult)
		{
			DWORD IocpSize = entry.dwNumberOfBytesTransferred;
			LPOVERLAPPED lpOverlapped = entry.lpOverlapped;
			ClientObject* pClientObject = (ClientObject*)entry.lpCompletionKey;
			stOverEx* ExData = (stOverEx*)lpOverlapped;

			if (lpOverlapped == pClientObject->GetOverlapped()) // recv buffer
			{
				if (IocpSize == 0)
				{
					std::cout << "error" << std::endl;
				}
				else
				{
					message mes;
					
				}
			}
		}
	}
}

