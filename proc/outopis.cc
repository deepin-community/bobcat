#include "proc.ih"

Proc::Out &Proc::Out::operator=(Out &&tmp)
{
    fswap(*this, tmp);
    return *this;
}
