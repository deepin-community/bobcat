#include "pipe.ih"

void Pipe::close()
{
    close(READ);
    close(WRITE);
}
