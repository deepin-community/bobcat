#include "immapstream.ih"

ImmapStream::ImmapStream(std::string const &fname, char const *bufSize)
:
    MmapBuf(fname, bufSize, ios::in),
    istream(this)
{}

