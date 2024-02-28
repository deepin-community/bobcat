#include "ldc.ih"

LDC::LDC(size_t nBytes, char const *bytes, size_t radix)
{
    setRadix(radix);
    init(nBytes, bytes);
}
