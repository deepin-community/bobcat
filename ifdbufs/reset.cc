#include "ifdbufs.ih"

void IFdBufS::reset(int fd, Mode mode, size_t size)
{
    d_selector.addReadFd(fd);

    IFdBuf::reset(fd, mode, size);


//    cleanup(mode);
//
//    d_fd = fd;
//
//    resize(size == 0 ? 1 : size);
//
//    setg(size, size);
}
