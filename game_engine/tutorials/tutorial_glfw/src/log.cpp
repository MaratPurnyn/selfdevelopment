#include "log.h"

Log::Log()
{
}
Log::~Log()
{
}

void Log::info(std::string msg)
{
    std::cout << msg << std::endl;
}