#include "proc.ih"

Proc::Activator::Activator(Activator &&tmp)
:
    d_pipesPtr(0)
{
    fswap(*this, tmp);
}

