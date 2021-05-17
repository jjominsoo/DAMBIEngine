#include "LogicQ.h"
#include "extern.h"
LogicQ::LogicQ()
{

}
bool LogicQ::isLogicEmpty()
{
    return LogicQueue.empty();
}

void LogicQ::Pop()
{
    mtx.lock();
    if (!LogicQueue.empty())
    {
        LogicQueue.pop();        
    }
    mtx.unlock();
}