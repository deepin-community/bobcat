#define XERR
#include "mmapbuf.ih"

// overrides
streamsize MmapBuf::showmanyc()
{
    return egptr() - gptr();
}
