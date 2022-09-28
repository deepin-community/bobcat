#include "iobuf.ih"

IOBuf::~IOBuf()
{
    if (d_out)
        sync();
}
