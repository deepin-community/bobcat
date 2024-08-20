#include "ldc.ih"

    // called by LDC(size_t nBytes, char const *bytes, ...)

void LDC::init(size_t nBytes, char const *bytes)
{
    if (nBytes == 0)
        throw Exception{} <<
            "'LDC(size_t nBytes, char const *bytes ...': nBytes must be >= 1";

    d_size = nBytes + SIZE;         // always at least VALUE bytes

    prepareBuffers();

    reverse_copy(bytes, bytes + nBytes, d_lsb);

    d_end = d_lsb + nBytes;         // beyond the last byte to convert

                                    // the first div value is stored before
                                    // d_end: there must always be enough
                                    // bytes to handle the value as VALUE
    guardBegin();
    setDivPtrs();

    convert();
}
