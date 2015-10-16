#include <chrono>
#include "time.h"

Time::Time()
{

}

long Time::getTime()
{
    auto t = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(t.time_since_epoch()).count();
}

void Time::setDelta(double delta)
{
    m_delta = delta;
}

