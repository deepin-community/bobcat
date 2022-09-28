#include "readlinebuf.ih"

int ReadLineBuf::underflow()
{
    size_t end = (this->*d_readline)();

    if (end == 0)
        return EOF;

    setg(&d_buffer[0], &d_buffer[0], &d_buffer[end]);

            // the static_cast<size_t char> is required to prevent
            // promotions of 0xff characters to -1, thus returning EOF...
    return static_cast<unsigned char>(*gptr());
}
