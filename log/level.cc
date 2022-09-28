#include "log.ih"

ostream &Log::level(size_t msgLevel)
{
    d_msgLevel = msgLevel;
    setActive(d_level <= d_msgLevel);

    return *this;
}
