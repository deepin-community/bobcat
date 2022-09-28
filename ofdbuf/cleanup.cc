#include "ofdbuf.ih"

void OFdBuf::cleanup(Mode mode)
{
    if (d_fd == -1)
        return;

    sync();

    if (d_mode == CLOSE_FD)
        close(d_fd);

    d_fd = -1;
}
    
