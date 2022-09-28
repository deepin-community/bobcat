#include "ifdbuf.ih"

void IFdBuf::reset(int fd, Mode mode, size_t size)
{
    cleanup(mode);

    d_fd = fd;
    
    resize(size == 0 ? 1 : size);

    setg(size, size);
}
