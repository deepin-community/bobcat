#include "pipe.ih"

int Pipe::writeOnlyFd()
{
    int ret = writeOnly();
    d_fd[WRITE] = -1;
    return ret;
}
