#include "pipe.ih"

Pipe &Pipe::operator=(Pipe &&tmp)
{
    close();
    FBB::fswap(*this, tmp);

    return *this;
}

