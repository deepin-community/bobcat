#include "ldc.ih"

void LDC::set(size_t nBytes, char const *bytes, string const &digits)
{
    LDC tmp{ nBytes, bytes, digits };
    swap(tmp);
}
