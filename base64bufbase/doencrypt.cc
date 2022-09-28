#include "base64bufbase.ih"

void Base64BufBase::doEncrypt()
{
    d_action = &Base64BufBase::encrypt;
}

