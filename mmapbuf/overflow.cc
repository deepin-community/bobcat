#define XERR
#include "mmapbuf.ih"

// override
int MmapBuf::overflow(int ch)
{
    // SF:   setp(d_buffer, d_buffer + d_bufSize);

        // when appending set d_pos to the last written position or
        // to the current fileSize. Not completely sure if this is
        // all it takes...
    if (d_openMode & ios::app)
        d_pos = max(d_fileSize, d_offset + (d_maxPtr - d_buffer));

    else if (d_activeBuffer)
        d_pos = d_offset + d_bufSize;  // set d_pos beyond the buffer

    // else: no active buffer -> d_pos was explicitly set
    // check if an mmapped buffer exists and d_pos is
    // within the buffer-area: then use the new put-position
    else if (d_buffer != 0 and withinBuffer(d_bufSize))
        return resetWriteBuffer(ch);

        // no active buffer, OR pptr() is not inside the d_buffer area
    sync();
    return writeBuffer(ch);
}
