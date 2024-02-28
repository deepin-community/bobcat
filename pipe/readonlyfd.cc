#include "pipe.ih"

int Pipe::readOnlyFd()
{
    int ret = readOnly();
    d_fd[READ] = -1;
    return ret;
}
