#include "ofdbuf.ih"

void OFdBuf::eoi_()
{
    cleanup(CLOSE_FD);
}
