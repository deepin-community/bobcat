#include "pipe.ih"

void Pipe::writtenBy(int const *fd, size_t n)
{
    close(READ);

    for (size_t idx = 0; idx != n; ++idx)
    {
        Redirector redirector{ d_fd[WRITE] };
        redirector.swallow(fd[idx]);
    }

    close(WRITE);
}
