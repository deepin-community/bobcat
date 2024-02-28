#include "ldc.ih"

LDC::LDC(size_t nBytes, char const *bytes, string const &digits)
{
    setRadix(digits);
    init(nBytes, bytes);
}
