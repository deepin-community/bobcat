#include "ldc.ih"

// static
pair<size_t, char *> LDC::bigIntBytes(BigInt const &bigInt)
{
    size_t size = bigInt.sizeInBytes();

    return (size == 0) ?
                pair<size_t, char *>{ 1, new char[1]{ 0 } }
            :
                pair<size_t, char *>{ size, bigInt.bigEndian() };
}
