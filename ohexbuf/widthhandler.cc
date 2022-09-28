#include "ohexbuf.ih"

void OHexBuf::widthHandler()
{
    d_count += 2 + d_separator.length();

    if (d_count >= d_width)
    {
        d_count = 0;
        out() << '\n';
    }
}
