#include "mapbase.ih"

void MapBase::unmap()
{
    if (not d_mMapped)
        return;

    if (munmap(d_cp, d_mapLength) != 0)
        cerr << "munmap for " << fname() << " failed\n";

    d_mMapped = false;
}
