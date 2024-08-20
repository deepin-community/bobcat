#include "ldc.ih"

ostream &LDC::showDiv(ostream &out) const
{
    out.fill('0');

    out << hex;

    for (CHAR *end = d_divEnd, *begin = d_divBegin; end-- != begin; )
        out << setw(2) << static_cast<unsigned>(*end) << ' ';

    out.fill(' ');

    return out << dec;
}
