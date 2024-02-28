#include "ldc.ih"

LDC &LDC::operator=(LDC &&tmp)
{
    swap(tmp);
    return *this;
}
