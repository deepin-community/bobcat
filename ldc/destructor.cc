#include "ldc.ih"

LDC::~LDC()
{
    for (size_t idx = 0; idx != 2; ++idx)
        delete[] d_buffer[idx];
}
