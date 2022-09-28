#include "config.ih"

Config &Config::operator=(Config &&tmp)
{
    swap(d_ptr, tmp.d_ptr);
    return *this;
}

