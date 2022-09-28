#include "osharedstream.ih"

OSharedStream::OSharedStream(size_t id, std::ios::openmode openMode)
:
    SharedBuf(id, openMode),
    std::ostream(this)
{}

