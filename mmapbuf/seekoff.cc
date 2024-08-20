#define XERR
#include "mmapbuf.ih"

// called by seekp()/tellp() (tellp using 0, ios::cur)

ios::pos_type MmapBuf::seekoff(ios::off_type pos, ios::seekdir where,
                               ios::openmode mode)
{
    return  seek(pos, where);
}
