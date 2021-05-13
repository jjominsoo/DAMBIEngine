#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <string>
#include <WinSock2.h>
#include "Logger.h"

static int ThreadEnd = 0;

extern Logger logger;
#define LOG_LEVEL_FATAL 10
#define LOG_LEVEL_ERROR 20
#define LOG_LEVEL_WARN 30
#define LOG_LEVEL_INFO 40
#define LOG_LEVEL_DEBUG 50
#define LOG_LEVEL_TRACE 60

#define LOG_FATAL(str, ...) logger.writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_FATAL, str, __VA_ARGS__)
#define LOG_ERROR(str, ...) logger.writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_ERROR, str, __VA_ARGS__)
#define LOG_WARN(str, ...) logger.writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_WARN, str, __VA_ARGS__)
#define LOG_INFO(str, ...) logger.writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_INFO, str, __VA_ARGS__)
#define LOG_DEBUG(str, ...) logger.writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_DEBUG, str, __VA_ARGS__)
#define LOG_TRACE(str, ...) logger.writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_TRACE, str, __VA_ARGS__)