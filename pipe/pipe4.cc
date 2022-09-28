#include "pipe.ih"

Pipe::Pipe(bool initialize)
{
    if (initialize)
        *this = Pipe{};
    else
    {
        d_fd[READ]  = -1;
        d_fd[WRITE] = -1;
    }
}
