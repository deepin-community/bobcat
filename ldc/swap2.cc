#include "ldc.ih"

void LDC::swap()
{
    d_lsb = d_divBegin;
    d_begin.ptr = d_lsb;
    d_end = d_divEnd;

    guardBegin();

    d_divEnd = d_buffer[d_cb] + d_size - SIZE;
    d_divBegin = d_divEnd;

    d_cb = not d_cb;
}
