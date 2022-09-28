#include "qpbufbase.ih"

string const QPBufBase::s_hexChars { "0123456789ABCDEF" };

void (QPBufBase::*QPBufBase::s_encode[])() =
{
    &QPBufBase::text,
    &QPBufBase::binary
};
    

