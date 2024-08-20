
#include "ecdh.ih"

// static
size_t ECDH::checkHex(char hexDigit)
{
    size_t idx = s_digits.find(hexDigit);
    if (idx == string::npos)
        throw Exception{} << "checkHex: invalid hex digit `" << 
                                                        hexDigit << '\'';

    return idx;
}
