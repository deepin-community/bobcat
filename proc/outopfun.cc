#include "proc.ih"

ostream &Proc::Out::operator()()
{
    return *d_stream;
}
