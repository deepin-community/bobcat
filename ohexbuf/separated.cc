#include "ohexbuf.ih"

void OHexBuf::separated(int ch)
{
    out() << setw(2) << ch << d_separator;
}
