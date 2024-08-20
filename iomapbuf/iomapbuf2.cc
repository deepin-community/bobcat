#include "iomapbuf.ih"

IOmapbuf::IOmapbuf(string const &fname, ios::openmode iosMode,
                   char const *bufSize, mode_t mode)
:
    MapBase(fname, iosMode, bufSize, mode)
{
    setp(0, 0);
    setg(0, 0, 0);
}
