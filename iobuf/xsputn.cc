#include "iobuf.ih"

std::streamsize IOBuf::xsputn(char const *buffer, streamsize n)
{
    return d_out->write(buffer, n) ? n : 0;
}
