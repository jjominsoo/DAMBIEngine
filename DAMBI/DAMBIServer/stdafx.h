#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <string>
#include <WinSock2.h>
#include "Logger.h"

extern Logger Log;

#define LOG_FATAL(str, ...) Log.LogPush(__FUNCTION__, __LINE__, LOG_LEVEL_FATAL, str, __VA_ARGS__)
#define LOG_ERROR(str, ...) Log.LogPush(__FUNCTION__, __LINE__, LOG_LEVEL_ERROR, str, __VA_ARGS__)
#define LOG_WARN(str, ...) Log.LogPush(__FUNCTION__, __LINE__, LOG_LEVEL_WARN, str, __VA_ARGS__)
#define LOG_INFO(str, ...) Log.LogPush(__FUNCTION__, __LINE__, LOG_LEVEL_INFO, str, __VA_ARGS__)
#define LOG_DEBUG(str, ...) Log.LogPush(__FUNCTION__, __LINE__, LOG_LEVEL_DEBUG, str, __VA_ARGS__)
#define LOG_TRACE(str, ...) Log.LogPush(__FUNCTION__, __LINE__, LOG_LEVEL_TRACE, str, __VA_ARGS__)