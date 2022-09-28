#include "ofdbuf.ih"

#include <iostream>

OFdBuf::OFdBuf(int fd, size_t bufSize)
:
    d_mode(CLOSE_FD)
{
    reset(fd, CLOSE_FD, bufSize);
}

