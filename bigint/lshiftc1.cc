#include "bigint.ih"

BigInt BigInt::lshiftc() const
{
    BigInt ret(*this);
    ret.lshift();
    return ret;
}
