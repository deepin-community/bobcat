#include "log.ih"

Log &Log::operator()(char accept)
{
    d_active->levelOK = false;
    d_active->opfunOK = d_active->accept.find(accept) != string::npos;

    setActive(d_active->opfunOK);
    d_level = ~0UL;             // stop level insertions

    return *this;
}

