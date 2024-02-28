#include "ldc.ih"

LDC &LDC::operator=(LDC const &rhs)
{
    return *this = LDC{ rhs };
}
