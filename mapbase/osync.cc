#define XERR
#include "mapbase.ih"

void MapBase::osync()
{
    if (not d_mMapped)
        return;

    size_t nWritten = pptr() - d_cp ;   // #bytes written into the buffer

//xerr("file size " << d_fileSize << ", offset: " << d_offset << \X========
//", nWritten: " << nWritten);


    if (nWritten > 0)                   // some bytes were written
    {
        if (msync(d_cp, nWritten, MS_SYNC) != 0)
            cerr << "msync " << d_fname << ": from " << d_offset <<
                    ", nBytes = " << nWritten << " failed\n";

        if (size_t size = d_offset + nWritten; d_fileSize < size)
{//xerr("enlarging file size from " << d_fileSize << " to " << size);
            d_fileSize = size;
}
    }
    unmap();
}

