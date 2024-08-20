#define XERR
#include "mmapbuf.ih"

int MmapBuf::writeBuffer(int ch)
{
    d_offset = d_pos / d_bufSize * d_bufSize;

    map(PROT_READ | PROT_WRITE);

    return resetWriteBuffer(ch);
}
