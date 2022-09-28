#include "pipe.ih"

Pipe::Pipe(int const *fd)
{
    memcpy(d_fd, fd, 2 * sizeof(int));
}
