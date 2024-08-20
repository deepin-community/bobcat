#define XERR
#include "omapbuf.ih"

Omapbuf &Omapbuf::operator=(Omapbuf &&tmp)
{
    moveAssign(move(tmp));
    load();
    return *this;
}
