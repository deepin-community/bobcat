#include "randbuf.ih"

#include <cstring>

int RandBuf::underflow()
{
    ostringstream ostr;

    d_buffer = 
        to_string(
                d_min + static_cast<int>(
                            (d_max - d_min) * (random() / (RAND_MAX + 1.))
                        )
        ) + ' ';

    setg(&d_buffer[0], &d_buffer[0], &d_buffer[d_buffer.length()]);

    return static_cast<unsigned char>(*gptr());
}

