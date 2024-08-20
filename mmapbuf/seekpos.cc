#define XERR
#include "mmapbuf.ih"

    // not called by tellp

// overrides
std::ios::pos_type MmapBuf::seekpos(ios::pos_type offset, ios::openmode mode)
{
    return seekoff(offset, ios::beg, mode);
}
