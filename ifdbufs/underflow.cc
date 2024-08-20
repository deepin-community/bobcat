#include "ifdbufs.ih"

int IFdBufS::underflow()
{
    d_selector.wait();

    return p_underflow();
}
