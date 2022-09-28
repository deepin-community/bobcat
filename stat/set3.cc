#include "stat.ih"

bool Stat::set(string const &name, string const &pathList)
{
    return setPath(::stat, name, pathList);
}









