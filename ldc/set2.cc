#include "ldc.ih"

void  LDC::set(size_t nBytes, char const *bytes, size_t radix)
{
    LDC tmp{ nBytes, bytes, radix };
    swap(tmp);
}
