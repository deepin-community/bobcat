#include "osymcryptbase.ih"

void OSymCryptBase::eoi_()
{
    if (d_eoi)
        return;

    evpUpdate();                // process available chars in the input
    d_eoi = true;
    resize(0);                  // clear the input buffer
    evpUpdate();                // update an empty buffer

}
