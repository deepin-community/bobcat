#define XERR
#include "omapbuf.ih"

bool Omapbuf::load()
{
    if (append())
        setAbsPos(fileSize(), ios::beg);

    if (not map(PROT_READ | PROT_WRITE))
        return false;

    setpBuf();
    return true;
}
