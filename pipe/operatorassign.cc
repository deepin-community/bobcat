#include "pipe.ih"

Pipe &Pipe::operator=(Pipe &&tmp)
{
    close();
    swap(tmp);

    return *this;
}
