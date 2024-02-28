#include "log.ih"

ostream &Log::level(size_t msgLevel)
{
    d_active->levelOK = d_level <= msgLevel;
    d_active->opfunOK = false;

    setActive(d_active->levelOK);         // maybe activate level logging

    return *this;
}
