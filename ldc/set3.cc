#include "ldc.ih"

void  LDC::set(string const &hexNr, string const &digits)
{
    LDC tmp{ hexNr, digits };
    swap(tmp);
}
