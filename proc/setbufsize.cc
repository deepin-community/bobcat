//#define XERR
#include "proc.ih"

size_t Proc::setBufSize(size_t bufSize)
{
    size_t ret = d_bufSize;
    d_bufSize =  bufSize == 0 ? 1 : bufSize;
    return ret;
}
