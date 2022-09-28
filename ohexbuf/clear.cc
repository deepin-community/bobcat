#include "ohexbuf.ih"

void FBB::OHexBuf::clear(bool reset)
{
    if (reset)
    {
        d_separator.clear();
        d_count = 0;
    }
}
