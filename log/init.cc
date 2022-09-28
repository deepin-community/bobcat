#include "log.ih"

void Log::init()
{
    d_msgLevel = ~0U;
    setLevel(0);
}
