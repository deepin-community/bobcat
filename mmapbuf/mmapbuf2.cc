#define XERR
#include "mmapbuf.ih"

MmapBuf::MmapBuf(string const &fname, char const *bufSize, 
                 ios::openmode openMode, mode_t mode)
:
    d_fname(fname),
    d_openMode(openMode),
    d_buffer(0),
    d_activeBuffer(false),
    d_pos(0),
    d_sync(false)
{
    setFileSize(mode);
    d_enlargedSize = d_fileSize;
    setBufSize(bufSize);

    if (openMode & ios::ate)
        d_pos = d_fileSize;
}
