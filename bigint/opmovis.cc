#include "bigint.ih"

BigInt &BigInt::operator=(BigInt &&tmp)
{
    swap(tmp);
    return *this;
}
