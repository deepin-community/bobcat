#include "proc.ih"

Proc::Out::Out(std::ostream *str, bool alloc)
:
    d_stream(str),
    d_alloc(alloc)
{}
