#include "sharedbuf.ih"

bool SharedBuf::mode(ios::openmode flag)
{
    if (not (d_currentMode & flag))
        return false;

    d_currentMode = flag;
    return true;
}
