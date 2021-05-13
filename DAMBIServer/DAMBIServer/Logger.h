#pragma once
#include <iomanip>
#include <fstream>
#include <ctime>
#include <sstream>
#include <mutex>

class Logger {
private:
    int logLevel;
    bool isOutput;
    std::string getTimestamp();

public:
    Logger();
    Logger(int level);
    std::mutex mtx;
    void writeLog(const char* funcName, int line, int level, const char* str, ...);
};

