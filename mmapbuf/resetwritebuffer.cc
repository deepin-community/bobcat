#define XERR
#include "mmapbuf.ih"

int MmapBuf::resetWriteBuffer(int ch)
{
    d_activeBuffer = true;

    setp(d_buffer, d_buffer + d_bufSize);
    pbump(d_pos - d_offset);


    *pptr() = ch;
    pbump(1);

    ++d_pos;
    d_sync = true;

    return ch;
}
