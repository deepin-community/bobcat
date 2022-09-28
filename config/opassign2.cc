#include "config.ih"

Config &Config::operator=(Config const &rhs)
{
    Config tmp(rhs);
    swap(d_ptr, tmp.d_ptr);
    return *this;
}

    
