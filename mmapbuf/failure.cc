#define XERR
#include "mmapbuf.ih"

void MmapBuf::failure(string msg)
{
    xerr(msg);
    throw Exception{} << msg;
}
