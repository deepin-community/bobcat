#define XERR
#include "mmapbuf.ih"

void MmapBuf::map(int protection)   // PROT_READ or PROT_READ | PROT_WRITE
{
        // note:  when reading  d_data,bufSize may exceed the file's size

    if (writable())
    {
        if (d_offset + d_bufSize > d_enlargedSize)
        {
            d_enlargedSize = d_offset + d_bufSize;
            fs::resize_file(d_fname, d_enlargedSize);
        }
    }

        
    mapBuffer(protection);                  // mmap the buffer, set d_buffer
}
