#include "mapbase.ih"

MapBase::~MapBase()
{
    unmap();
    if (d_orgSize < d_fileSize)
        fs::resize_file(d_fname, d_fileSize);
        
}
