#pragma once
void LogicThread();
void LogThread();
void WorkerThread(HANDLE hIOCP);
void AcceptThread(SOCKET ServerSocket);