#include "iommapstream.ih"

IOmmapStream::IOmmapStream(string const &fname, char const *bufSize,
                         IOS::openmode openMode, mode_t mode)
:
    MmapBuf(fname, bufSize, openMode, mode),
    iostream(this)
{}

