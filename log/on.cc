#include "log.ih"

void  Log::on(size_t logLevel)
{
    setActive(ACTIVE);
    setLevel(logLevel);
    
}
