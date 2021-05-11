#pragma once

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdarg>
#include <ctime>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <mutex>

using namespace std;
class Logger {
private:
   
    int logLevel;
    bool isOutput;
    string getTimestamp();

public:
    std::mutex mtx;
    Logger();
    Logger(int level);
    void writeLog(const char* funcName, int line, int level, const char* str, ...);
};

