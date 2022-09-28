#include "ohexbuf.ih"

OHexBuf::~OHexBuf()
{
    eoi_();
    out().fill(d_padding);
    out().flags(d_current);
}
