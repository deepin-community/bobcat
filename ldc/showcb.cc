#include "ldc.ih"

ostream &LDC::showCb(ostream &out) const
{
    out.fill('0');

    out << hex;

    for (CHAR *end = d_end, *begin = d_begin.ptr; end-- != begin; )
        out << setw(2) << static_cast<unsigned>(*end);
    out << '\n';

    for (CHAR *end = d_end, *begin = d_begin.ptr; end-- != begin; )
        out << setw(2) << static_cast<unsigned>(*end) << ' ';

    out << "| ";

    for (CHAR *end = d_begin.ptr, *begin = d_lsb; end-- != begin; )
        out << setw(2) << static_cast<unsigned>(*end) << ' ';

    out.fill(' ');
    return out << dec;
}
