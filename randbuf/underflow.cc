#include "randbuf.ih"

int RandBuf::underflow()
{
    ostringstream ostr;

    d_buffer = to_string(d_randomMT()) + ' ';

    setg(
        &d_buffer.front(), &d_buffer.front(), 
         &d_buffer.front() + d_buffer.length()
    );

    return static_cast<unsigned char>(*gptr());
}
