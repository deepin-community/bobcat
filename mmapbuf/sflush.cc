#define XERR
#include "mmapbuf.ih"

void MmapBuf::sflush()
{
    size_t nChars = max(pptr(), d_maxPtr) - d_buffer;

                                            // enlarge the fileSize if needed
    if (nChars != 0 and d_fileSize < d_offset + nChars)
       d_fileSize = d_offset + nChars;
}
