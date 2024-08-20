#include "ldc.ih"

LDC::LDC(string const &hexStr, size_t radix)    // e.g., deadbeef, no 0x
{
    setRadix(radix);
    init(hexStr);
}
