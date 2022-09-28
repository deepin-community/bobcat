#include "ohexbuf.ih"

// overrides
int OHexBuf::overflow(int ch)
{
    (this->*d_separated)(ch);
    (this->*d_widthHandler)();

    return ch;
}

