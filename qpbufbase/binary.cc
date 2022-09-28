#include "qpbufbase.ih"

void QPBufBase::binary()
{
    escape('\n');
    flush();
}
