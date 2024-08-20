#define XERR
#include <bobcat/fswap>

#include "mmapbuf.ih"

MmapBuf &MmapBuf::operator=(MmapBuf &&tmp)
{
    fswap(&d_openMode, *this, tmp);
    return *this;
}
