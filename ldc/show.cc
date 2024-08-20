#include "ldc.ih"

// static
ostream &LDC::show(ostream &out, string const &arg)
{
    out << "Lowest idx first: " << hex;
    for (char const &byte: arg)
        out << static_cast<unsigned>(byte);

    return out << dec;
}
