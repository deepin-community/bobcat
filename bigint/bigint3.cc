#include "bigint.ih"

BigInt::BigInt(BigInt &&tmp)
:
    d_bn(tmp.d_bn)
{
    tmp.d_bn = BN_new();
}
