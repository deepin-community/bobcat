#include "ldc.ih"

void LDC::compressDigits(string const &hexNr)
{
    d_end = d_lsb;                  // append bytes at d_end

    size_t value = 0;               // stores 2 nibbles
                                    // 1, 2, 3, 4, ...:
                                    // 1 in lowest nibble, 2 in highest
    size_t nibble = 0;
    for (char const &ch: hexNr)     // ch values are hexNr's characters
    {
        value = (ch << nibble) | value;
        nibble += 4;
        if (nibble == 8)
        {
            nibble = 0;
            *d_end++ = value;
            value = 0;
        }
    }

    if (value != 0)
        *d_end++ = value;
}
