#define XERR
#include "mmapbuf.ih"

bool MmapBuf::withinBuffer(size_t bufSize) const
{
    return d_offset <= d_pos and d_pos < d_offset + bufSize;    
}

