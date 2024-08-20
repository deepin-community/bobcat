#include "mapbase.ih"

bool MapBase::readingMapLength()
{
    if (d_offset >= d_orgSize)
        return false;                   // no chars for the reading mmap

                                        // otherwise use a full/partial buffer
    d_mapLength = min(d_orgSize, d_offset + d_bufferSize) - d_offset;
    return true;
}
