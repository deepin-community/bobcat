#include "ldc.ih"

void LDC::installDiv(VALUE div10Value)
{
    size_t nBytes = d_end - d_begin.ptr;        // # bytes in th current value

    Cpt div10{ .value = div10Value };           // obtain div10Value's bytes

    d_divBegin -= nBytes;                       // begin of the div10Value:

    if (div10.bytes[nBytes - 1] == 0)           // if div10's MSB == 0
    {                                           // then ignore the MSB
        --nBytes;
        ++d_divBegin;
    }

                                        // cp div10Value to the the div-buffer
    copy(div10.bytes, div10.bytes + nBytes, d_divBegin);
}
