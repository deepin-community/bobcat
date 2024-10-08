#include "bigint.ih"

// static
BigInt BigInt::randRange(BigInt const &max)
{
    BigInt ret;
    if (BN_rand_range(ret.d_bn, const_cast<BIGNUM *>(max.d_bn)) != 1)
        throw Exception{} << "BigInt::randRange() failed";
    return ret;
}
