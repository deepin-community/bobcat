#include "omapbuf.ih"

    // the file is created (to size 0) if not existing and create was
    // specified and the write-flag(s) of mode are set.

Omapbuf::Omapbuf(string const &fname, ios::openmode iosMode, 
                 char const *bufSize, mode_t mode)
:
    MapBase(fname, iosMode | ios::out, bufSize, mode)
{
    setp(0, 0);                 // start w/o an mmapped buffer
}



