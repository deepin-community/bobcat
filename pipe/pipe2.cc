#include "pipe.ih"

Pipe::Pipe(Pipe &&tmp)
:
    d_fd{ -1, -1}
{
    FBB::fswap(*this, tmp);
}
