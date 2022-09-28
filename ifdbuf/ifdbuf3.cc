#include "ifdbuf.ih"

IFdBuf::IFdBuf(int fd, size_t size)
:
    d_mode(KEEP_FD)         // comply with old default
{
    reset(fd, KEEP_FD, size);
}
