#include "ommapstream.ih"

void OmmapStream::open(string const &fname, char const *bufSize,
                       IOS::openmode openMode, mode_t mode)
{
    *this = OmmapStream{ fname, bufSize, openMode, mode };
}
