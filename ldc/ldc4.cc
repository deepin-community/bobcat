#include "ldc.ih"

LDC::LDC(BigInt const &bigInt, size_t radix)
:
    LDC()
{
    auto [nBytes, bytes] = bigIntBytes(bigInt);
    LDC tmp{ nBytes, bytes, radix };
    delete[] bytes;
    swap(tmp);
}
