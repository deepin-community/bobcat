#define XERR
#include "mmapbuf.ih"

int MmapBuf::readBuffer()
{
    unmap();

    if (d_pos >= d_fileSize)
        return EOF;

    d_offset = d_pos / d_bufSize * d_bufSize;

    d_readBufSize = min(d_fileSize - d_offset, d_bufSize);

    map(writable() ? PROT_READ | PROT_WRITE : PROT_READ);

    return resetReadBuffer();
}
