#include "ifdbufs.ih"

IFdBufS::IFdBufS(int fd, size_t size)
:
    IFdBuf(fd, size)
//    d_mode(KEEP_FD)
{
    d_selector.addReadFd(fd);
//    reset(fd, KEEP_FD, size);
}

