#include "osharedstream.ih"

void OSharedStream::open(
                size_t maxSize, SizeUnit sizeUnit,
                std::ios::openmode openMode, size_t access)
{
    setMemory(SharedMemory(maxSize, sizeUnit, access));
    setOpenMode(openMode);
    clear();
}
