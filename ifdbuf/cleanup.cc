#include "ifdbuf.ih"

void IFdBuf::cleanup(Mode mode)
{
//    CERRX << buffer() << '\n';

    if (d_fd == -1)
        return;

    if (mode == CLOSE_FD)
        ::close(d_fd);

    d_fd = -1;
}
