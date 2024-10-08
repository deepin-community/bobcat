#include "bigint.ih"

BigInt BigInt::addModc(BigInt const &rhs, BigInt const &mod) const
{
    BigInt ret(*this);
    ret.addMod(rhs, mod);
    return ret;
}
