#include "bigint.ih"

BigInt BigInt::maskBitsc(size_t lowerNBits) const
{
    BigInt ret(*this);
    ret.maskBits(lowerNBits);
    return ret;
}
