
#include "omapbuf.ih"

// overrides
Omapbuf::~Omapbuf()
{
    sync();
    fs::resize_file(fname(), realSize());
}
