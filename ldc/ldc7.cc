#include "ldc.ih"

LDC::LDC(BigInt const &bigInt, string const &digits)
:
    LDC()
{
    auto [nBytes, bytes] = bigIntBytes(bigInt);
    LDC tmp{ nBytes, bytes, digits };
    delete[] bytes;
    swap(tmp);
}
