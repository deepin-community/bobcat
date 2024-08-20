#include "ldc.ih"

void LDC::prepareBuffers()
{
    for (size_t idx = 0; idx != 2; ++idx)
        d_buffer[idx] = new CHAR[d_size]();

    d_lsb = d_buffer[0];            // begin location of hexNr's compressed
}
