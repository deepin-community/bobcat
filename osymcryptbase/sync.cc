#include "osymcryptbase.ih"

int OSymCryptBase::sync()
{
    evpUpdate();
    d_outStream.flush();
    return 0;
}
