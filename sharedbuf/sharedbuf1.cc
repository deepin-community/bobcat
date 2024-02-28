#include "sharedbuf.ih"

SharedBuf::SharedBuf()
:
    d_openMode(static_cast<ios::openmode>(0)),
    d_currentMode(d_openMode)
{
    setg(0, 0, 0);
    setp(0, 0);
}
