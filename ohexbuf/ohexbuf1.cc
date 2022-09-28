#include "ohexbuf.ih"

OHexBuf::OHexBuf(ostream &out, size_t width, 
                             string const &separator) 
:
    OFilterBuf(out),
    d_current(out.flags()),
    d_padding(out.fill('0')),
    d_count(0),
    d_separator(separator),
    d_separated(separator.empty() ? 
                        &OHexBuf::plain
                    :
                        &OHexBuf::separated)
{
    setWidth(width);
    out << hex;
}

