#include "iommapstream.ih"

void IOmmapStream::open(string const &fname, char const *bufSize,
                       IOS::openmode openMode, mode_t mode)
{
    *this = IOmmapStream{ fname, bufSize, openMode, mode };
}
