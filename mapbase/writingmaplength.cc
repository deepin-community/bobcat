#include "mapbase.ih"

void MapBase::writingMapLength()
{
    d_mapLength = d_bufferSize;

    if (d_offset + d_bufferSize > d_enlargedSize)
    {
        d_enlargedSize = d_offset + d_bufferSize;    // enlarge the file
        fs::resize_file(d_fname, d_enlargedSize);
    }
}
