#define XERR
#include "mmapbuf.ih"

MmapBuf::MmapBuf(MmapBuf &&tmp)
:
    streambuf(static_cast<streambuf &&>(tmp))
{
    if (not d_fname.empty())
    {        
        if (writable())
            sync();
        else
            unmap();
    }

    d_fname = move(tmp.d_fname);
    d_openMode = tmp.d_openMode;

    d_buffer = tmp.d_buffer;
    d_bufSize = tmp.d_bufSize;

    d_fileSize = tmp.d_fileSize;
    d_enlargedSize = tmp.d_enlargedSize;

    d_activeBuffer = tmp.d_activeBuffer;
    d_pos = tmp.d_pos;

    d_offset = tmp.d_offset;
    d_maxPtr = tmp.d_maxPtr;

    d_sync = tmp.d_sync;
}



