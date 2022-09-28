#include "ohexbuf.ih"

void OHexBuf::separator(bool reset)
{
    d_separated = &OHexBuf::plain;
    clear(reset);
}
