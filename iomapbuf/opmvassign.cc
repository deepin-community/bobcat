#include "iomapbuf.ih"

IOmapbuf &IOmapbuf::operator=(IOmapbuf &&tmp)
{
    moveAssign(move(tmp));
    if (Omapbuf::load())
        setg(begin(), next(), end());

    return *this;
}
