#include "qpbufbase.ih"

void QPBufBase::doEncode(bool binary)
{
    d_encode = binary? &QPBufBase::binary : &QPBufBase::text;
    d_action = &QPBufBase::encode;
}

