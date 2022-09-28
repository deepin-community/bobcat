#include "ohexbuf.ih"

int OHexBuf::sync()
{
    out() << flush;
    return 0;
}

