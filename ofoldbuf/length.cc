#include "ofoldbuf.ih"

size_t OFoldBuf::length() const
{
    return d_next + d_wsLength + d_nonWs.length();
}
