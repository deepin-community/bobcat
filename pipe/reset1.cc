#include "pipe.ih"

void Pipe::reset()
{
    close();

    Pipe tmp;
    swap(tmp);
}

