#include "bigint.ih"

BigInt::BigInt([[maybe_unused]] Little dummy, string bytes, bool negative)
:
    BigInt()
{
    reverse(bytes.begin(), bytes.end());        // convert to big endian
    BigInt tmp(bytes, negative);                // construct the BigInt
    swap(tmp);                                  // install it
}
