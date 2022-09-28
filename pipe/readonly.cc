#include "pipe.ih"

int Pipe::readOnly()
{
    close(WRITE);
    return d_fd[READ];
}
