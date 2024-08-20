//#define XERR
#include "proc.ih"

void Proc::toOut()
{
    if (d_writeOut != d_pipesPtr->size() - 1)
        return;

    IFdBufS buf{ (*d_pipesPtr)[d_writeOut].readOnlyFd(), d_bufSize };

    d_out() << &buf;
    d_out().clear();       // clear because '<< &buf' may return EOF
}
