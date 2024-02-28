#include "pipe.ih"

void Pipe::writtenBy(int const *fd, size_t nSwallow)
{
    close(READ);

    for (size_t idx = 0; idx != nSwallow; ++idx)
    {
        Redirector redirector{ d_fd[WRITE] };
        redirector.swallow(fd[idx]);
    }

    close(WRITE);
}
