#include "bigint.ih"

BigInt::BigInt(size_t length, char const *bytes, bool negative)
:
    BigInt()
{
                                                    // construct the BigInt
    BigInt tmp{ Little{}, string{ bytes, bytes + length }, negative };
    swap(tmp);                              // install it.
}
