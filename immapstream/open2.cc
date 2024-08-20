#include "immapstream.ih"

void ImmapStream::open(string const &fname, char const *bufSize)
{
    *this = ImmapStream{ fname, bufSize };
}
