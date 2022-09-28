#include "stat.ih"

void Stat::init(int (*statFun)(char const *, stat *))
{
    d_errno = (*statFun)(d_name.c_str(), &d_stat) ? 
                    errno
                :
                    0;
}
