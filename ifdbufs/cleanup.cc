#include "ifdbufs.ih"

void IFdBufS::cleanup(Mode mode)
{
    d_selector = Selector{};

    if (fd() == -1)
        return;

    if (mode == CLOSE_FD)
        ::close(fd());

    setFd(-1);
}
