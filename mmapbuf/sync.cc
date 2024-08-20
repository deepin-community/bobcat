#define XERR
#include "mmapbuf.ih"

// override
int MmapBuf::sync()
{
    if (d_buffer != 0)             // sync only needed when there's a buffer
    {
        sflush();
        unmap();
    }

    d_sync = false;
    return 0;
}
