#include "ldc.ih"

namespace
{
    string digits{ "0123456789abcdefghijklmnopqrstuvwxyz" };
}

void LDC::setRadix(size_t radix)
{
    if (radix < 2 or radix > 36)
        throw Exception{} << "radix must be >= 2 and <= 36";

    setRadix(digits.substr(0, radix));
}
