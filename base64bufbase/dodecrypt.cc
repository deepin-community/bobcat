#include "base64bufbase.ih"

void Base64BufBase::doDecrypt()
{
    d_action = &Base64BufBase::decrypt;
//    setBuffer();
}

