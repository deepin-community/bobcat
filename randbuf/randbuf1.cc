#include "randbuf.ih"

RandBuf::RandBuf(int minimum, int maximum, size_t seed)
:
    d_randomMT(min(minimum, maximum), max(minimum, maximum), seed)
{
    setg(0, 0, 0);
}
