#include "iommapstream.ih"

IOmmapStream::IOmmapStream()
:
    MmapBuf(),
    iostream(this)
{}
