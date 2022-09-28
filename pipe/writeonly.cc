#include "pipe.ih"

int Pipe::writeOnly()
{
    close(READ);
    return d_fd[WRITE];
}
