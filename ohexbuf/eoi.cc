#include "ohexbuf.ih"

#include <iostream>

void OHexBuf::eoi_()
{
    sync();
    separator();
    setWidth(0);
}
