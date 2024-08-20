#define XERR
#include "mmapbuf.ih"

size_t MmapBuf::writen(char const **bufferPtr, size_t toWrite)
{
    memcpy(pptr(), *bufferPtr, toWrite);
    *bufferPtr += toWrite;

    pbump(toWrite);
    return toWrite;
}
