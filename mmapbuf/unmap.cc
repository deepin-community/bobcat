#define XERR
#include "mmapbuf.ih"

void MmapBuf::unmap()
{
    if (d_buffer == 0)
        return;

        // mmap and munmap accept buffers for reading exceeding the file size
    if (munmap(d_buffer, d_bufSize) != 0)
        failure("munmap for " + d_fname + " failed");

    d_buffer = 0;           // no buffer available anymore
}
