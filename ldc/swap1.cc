#include "ldc.ih"

void LDC::swap(LDC &other)
{
    fswap(*this, other, d_converted, d_digits);
}
