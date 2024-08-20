#include "ldc.ih"

void LDC::setRadix(string const &digits)
{
    if (digits.length() < 2)
        throw Exception{} << "at least 2 digits must be specified";

    d_digits = digits;
    d_radix = d_digits.length();
}
