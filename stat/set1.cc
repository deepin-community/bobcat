#include "stat.ih"

bool Stat::set(string const &name)
{
    return set(::stat, name);
}
