#define XERR
#include "mmapbuf.ih"

std::ios::pos_type MmapBuf::seek(IOS::off_type pos, IOS::seekdir where)
{
    switch (where)
    {
        case ios::beg:
            d_pos = pos;
        break;

        case ios::end:
            d_pos = d_fileSize + pos;
        break;

        case ios::cur:
        {
            if (not d_activeBuffer)
            {
                d_pos += pos;
                break;
            }

            // d_buffer has a value so over/underflow has set buffer ptrs

            size_t pPos = 0;            // needed when only writing
            if (pbase() != 0)           // get the current write-position
            {
                pPos = d_offset + (pptr() - pbase());
                d_maxPtr = max(d_maxPtr, pptr());
                // check/update maxPtr
            }

            size_t gPos = 0;            // needed when reading
            if (eback() != 0)           // get the current read position
                gPos = d_offset + (gptr() - eback());

                // use the farthest position = the position after the most
                //  recent read or write
            d_pos = max(pPos, gPos) + pos;
        }
        break;
    }

    setp(0, 0);                         // forcing under/overflow
    setg(0, 0, 0);

    d_activeBuffer = false;

    return d_pos;
}
