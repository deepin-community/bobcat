#include "arg.ih"

Arg::~Arg()
{
    delete d_ptr;
}
