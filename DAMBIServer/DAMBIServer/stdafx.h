#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <WinSock2.h>
#include "Logger.h"

extern Logger logger;
#define LOG_LEVEL_FATAL 10
#define LOG_LEVEL_ERROR 20
#define LOG_LEVEL_WARN 30
#define LOG_LEVEL_INFO 40
#define LOG_LEVEL_DEBUG 50
#define LOG_LEVEL_TRACE 60

#define LOG_FATAL(str, ...) logger.writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_FATAL, str, __VA_ARGS__)
#define error(str, ...) logger.writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_ERROR, str, __VA_ARGS__)
#define warn(str, ...) logger.writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_WARN, str, __VA_ARGS__)
#define info(str, ...) logger.writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_INFO, str, __VA_ARGS__)
#define debug(str, ...) logger.writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_DEBUG, str, __VA_ARGS__)
#define trace(str, ...) logger.writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_TRACE, str, __VA_ARGS__)

