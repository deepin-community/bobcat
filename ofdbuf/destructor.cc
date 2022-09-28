#include "ofdbuf.ih"

OFdBuf::~OFdBuf()
{
    cleanup(d_mode);
}

