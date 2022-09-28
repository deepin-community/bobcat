#include "ofilterbuf.ih"

void OFilterBuf::reset(std::ostream &out)
{
    d_out->flush();
    d_dest.close();
    d_out = &out;
}
