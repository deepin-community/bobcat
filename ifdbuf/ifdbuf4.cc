#include "ifdbuf.ih"

IFdBuf::IFdBuf(int fd, Mode mode, size_t size)
:
    d_mode(mode)
{
    reset(fd, KEEP_FD, size);
}
