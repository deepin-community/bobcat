#include "ifdbuf.ih"

IFdBuf::~IFdBuf()
{
    cleanup(d_mode);
}

