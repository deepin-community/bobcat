#include "pipe.ih"

void Pipe::close(RW rw)
{
    if (d_fd[rw] == -1)
        return;

    ::close(d_fd[rw]);
    d_fd[rw] = -1;
}
