#include "ifilterbuf.ih"

std::streamsize IFilterBuf::showmanyc()
{
    return (d_srcEnd - d_srcBegin) + (egptr() - gptr());
}
