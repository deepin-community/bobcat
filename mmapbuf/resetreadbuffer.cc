#define XERR
#include "mmapbuf.ih"

int MmapBuf::resetReadBuffer()
{
    setg(d_buffer, d_buffer, d_buffer + d_readBufSize);
    gbump(d_pos - d_offset);

    d_activeBuffer = true;

    return static_cast<unsigned char>(*gptr());
}
