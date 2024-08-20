#include "ommapstream.ih"

OmmapStream::OmmapStream(string const &fname, char const *bufSize,
                         IOS::openmode openMode, mode_t mode)
:
    MmapBuf(fname, bufSize, openMode, mode),
    ostream(this)
{}

