#include "pipe.ih"

void Pipe::reset(int const *fds)
{
    close();
    Pipe tmp{ fds };
    swap(tmp);
}
