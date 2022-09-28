#include "sharedbuf.ih"

int SharedBuf::overflow(int ch)
{
    return mode(ios::out) ? d_memory.put(ch) : EOF;
}
