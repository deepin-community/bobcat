#include "pipe.ih"

void Pipe::readFrom(int const *fd, size_t n)
{
    close(WRITE);

    for (size_t idx = 0; idx != n; ++idx)
    {
        Redirector redirector{ d_fd[READ] };
        redirector.swallow(fd[idx]);
    }

    close(READ);
}
