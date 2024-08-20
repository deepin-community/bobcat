#define XERR
#include "mmapbuf.ih"

// override
int MmapBuf::underflow()
{
    if (d_sync)
        sync();

                                        // active buffer and underflow: 
    if (d_activeBuffer)                 // the buffer is exhausted
        d_pos = d_offset + d_bufSize;   // set d_pos beyond the buffer

        // else: no active buffer anymore -> d_pos was explicitly set
                    // check if an mmapped buffer exists and d_pos is
                    // within the buffer-area: then use the new get-position

    return (d_buffer != 0 and withinBuffer(d_readBufSize)) ?
                resetReadBuffer()
            :
                readBuffer();
}
