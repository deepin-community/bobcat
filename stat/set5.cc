#include "stat.ih"

bool Stat::set(int (*statFun)(char const *, stat *), string const &name)
{
    d_name = name;
    init(statFun);
    return !d_errno;
}
