#include "datetime.ih"

// static
int DateTime::stdFind(char const **names, int count, string const &target)
{
    int ret = find(names, names + count, target) - names;

    if (ret == count)               // not found
        throw 1;

    return ret;
}
