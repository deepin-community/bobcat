#include "bigint.ih"

char *BigInt::littleEndian() const
{
    size_t nBytes = sizeInBytes();

    char *ret = new char[nBytes];

    BN_bn2bin(d_bn, reinterpret_cast<unsigned char *>(ret));

    reverse(ret, ret + nBytes);

    return ret;
}
