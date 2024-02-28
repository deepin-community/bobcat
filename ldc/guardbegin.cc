#include "ldc.ih"

void LDC::guardBegin()
{
    d_begin.ptr = d_end - SIZE;

    if (d_begin.ptr < d_lsb)        // reset for smaller values
        d_begin.ptr = d_lsb;
}
