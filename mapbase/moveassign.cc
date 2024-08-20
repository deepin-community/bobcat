#include "mapbase.ih"

void MapBase::moveAssign(MapBase &&tmp)
{
    unmap();            // osync for writing modes?

    d_writing = tmp.d_writing;
    d_mMapped = tmp.d_mMapped;
    d_fname = std::move(tmp.d_fname);
    d_mode = tmp.d_mode;
    d_offset = tmp.d_offset;
    d_absPos = tmp.d_absPos;
    d_absolute = tmp.d_absolute;
    d_cp = tmp.d_cp;

    d_fileSize = tmp.d_fileSize;
    d_orgSize = tmp.d_orgSize;
    d_enlargedSize = tmp.d_enlargedSize;

    d_bufferSize = tmp.d_bufferSize;
    d_mapLength = d_bufferSize;
    
    tmp.d_mMapped = false;  // prevent actions by tmp's destructor
    tmp.d_orgSize = 0;
    tmp.d_fileSize = 0;
}
