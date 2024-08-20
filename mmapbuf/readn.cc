#define XERR
#include "mmapbuf.ih"

size_t MmapBuf::readn(char **dest, size_t toRead)
{
    memcpy(*dest, gptr(), toRead);
    *dest += toRead;
    gbump(toRead);

    return toRead;
}
