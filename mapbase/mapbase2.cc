#define XERR
#include "mapbase.ih"

MapBase::MapBase(std::string const &name, ios::openmode iosMode, 
                 char const *bufSize, mode_t mode)
:
    d_writing((iosMode & (ios::out | ios::app)) != 0),
    d_mMapped(false),
    d_fname(name),
    d_mode(iosMode),
    d_offset(0),
    d_absPos(0),
    d_absolute(true),
    d_cp(0)
{
    setFileSize(mode);
    d_fileSize = d_orgSize;
    d_enlargedSize = d_orgSize;
    setBufLength(bufSize);
    d_mapLength = d_bufferSize;

    if ((iosMode & ios::ate) or (iosMode & ios::app))
        d_absPos = d_fileSize;
}
