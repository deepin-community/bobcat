#include "log.ih"

void Log::setLevel(size_t logLevel)
{
    d_level = logLevel;
    level(~0U);
}
