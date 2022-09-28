#include "selector.ih"

// static
bool Selector::isEmpty(fd_set const &set)
{
    static fd_set empty;
    return memcmp(&set, &empty, sizeof(fd_set)) == 0;
}

