#include "iomapbuf.ih"

std::ios::pos_type IOmapbuf::seekpos(ios::pos_type offset, ios::openmode mode)
{
    return seekoff(offset, ios::beg, mode);
}
