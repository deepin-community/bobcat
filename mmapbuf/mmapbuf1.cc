#define XERR
#include "mmapbuf.ih"

MmapBuf::MmapBuf()
:
    d_openMode(static_cast<IOS::openmode>(0)),
    d_buffer(0),
    d_bufSize(0),
    d_fileSize(0),
    d_enlargedSize(0),
    d_activeBuffer(false),
    d_pos(0),
    d_offset(0),
    d_maxPtr(0)
{}
