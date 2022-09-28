#include "ohexbuf.ih"

void OHexBuf::separator(string const &sep, bool reset)
{
    d_separator = sep;
    d_separated = &OHexBuf::separated;
    clear(reset);
}
