#include "isharedstream.ih"

ISharedStream::ISharedStream(size_t id, std::ios::openmode openMode)
:
    SharedBuf(id, openMode),
    istream(this)
{}

