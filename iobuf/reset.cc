#include "iobuf.ih"

void IOBuf::reset(std::istream &in, std::ostream &out)
{
    if (d_out)
        sync();

    d_in = &in;
    d_out = &out;
    setg(&d_buf, &d_buf + 1, &d_buf + 1);
}
