#include "pipe.ih"

void Pipe::readFrom(int const *fd, size_t nSwallow)
{
    close(WRITE);

    for (size_t idx = 0; idx != nSwallow; ++idx)
    {
        Redirector redirector{ d_fd[READ] };
        redirector.swallow(fd[idx]);
    }

    close(READ);
}
