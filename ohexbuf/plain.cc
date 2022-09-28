#include "ohexbuf.ih"

void OHexBuf::plain(int ch)
{
    out() << setw(2) << ch;
}
