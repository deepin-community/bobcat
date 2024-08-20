#include "ldc.ih"

LDC &LDC::operator=(std::string const &hexStr)
{
    set(hexStr);
    return *this;
}
