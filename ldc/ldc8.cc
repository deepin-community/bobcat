#include "ldc.ih"

LDC::LDC(LDC const &other)
:
    d_size(other.d_size),
    d_radix(other.d_radix),
    d_cb(other.d_cb),
    d_converted(other.d_converted)
{
    prepareBuffers();

    d_lsb = d_buffer[d_cb];
    d_end = d_lsb + (other.d_end - other.d_buffer[d_cb]);
    d_begin.ptr = d_lsb + (other.d_begin.ptr - other.d_buffer[d_cb]);

    d_lsb += other.d_lsb - other.d_buffer[d_cb];

    d_divEnd = d_buffer[not d_cb];
    d_divBegin = d_divEnd + (other.d_divBegin - other.d_buffer[not d_cb]);
    d_divEnd += other.d_divEnd - other.d_buffer[not d_cb];
}
