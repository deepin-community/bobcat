#include "qpbufbase.ih"

void QPBufBase::text()
{
    flush();
    d_buffer += '\n';
}
