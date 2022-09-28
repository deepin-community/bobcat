#include "multibuf.ih"

int MultiBuf::overflow(int c)
{
    if (c == EOF)
        sync();
    else 
        d_buffer += c;

    return c;
}

