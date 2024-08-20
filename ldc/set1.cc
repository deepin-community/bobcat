#include "ldc.ih"

void LDC::set(string const &hexNr, size_t radix)    // e.g., deadbeef, no 0x
{
    LDC tmp{ hexNr, radix };
    swap(tmp);
}
