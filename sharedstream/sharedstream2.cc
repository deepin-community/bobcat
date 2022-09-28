#include "sharedstream.ih"

SharedStream::SharedStream(
                size_t maxSize, SharedMemory::SizeUnit sizeUnit,
                std::ios::openmode openMode, size_t access)
:
    SharedBuf(maxSize, sizeUnit, openMode, access),
    std::istream(this),
    std::ostream(this)
{}

