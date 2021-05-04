#pragma once
void LogicThread();
void WorkerThread(HANDLE hIOCP);
void AcceptThread(SOCKET ServerSocket);