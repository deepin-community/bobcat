#include "ifdbufs.ih"

IFdBufS::IFdBufS(int fdarg, Mode mode, size_t size)
:
    IFdBuf(fdarg, mode, size)
    // d_mode(mode)
{
    d_selector.addReadFd(fd());
    //reset(fd, KEEP_FD, size);
}

