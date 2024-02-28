#include "ldc.ih"

LDC::LDC(string const &hexStr, string const &digits) // e.g., deadbeef, no 0x
{
    setRadix(digits);
    init(hexStr);
}
