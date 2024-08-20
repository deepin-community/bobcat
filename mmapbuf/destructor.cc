#define XERR
#include "mmapbuf.ih"

// overrides
MmapBuf::~MmapBuf()
{
    if (not writable())
        unmap();
    else
    {
        sync();
        fs::resize_file(d_fname, d_fileSize);
    }
}
