#include "immapstream.ih"

ImmapStream::ImmapStream()
:
    MmapBuf(),
    istream(this)
{}
