#define XERR
#include "mapbase.ih"

void MapBase::setpBuf()
{
    setp(d_cp, d_cp + d_mapLength);
    pbump(d_absPos - d_offset);

//xerr("MapBase " << d_absPos << " pbump to " << (d_absPos - d_offset));
}
