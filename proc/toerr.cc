//#define XERR
#include "proc.ih"

void Proc::toErr()
{
    int fd = (*d_pipesPtr)[d_writeErr].readOnlyFd();

    IFdBufS buf{ fd, d_bufSize };
    d_err() << &buf;
    d_err().clear();       // clear because '<< &buf' may return EOF
}
