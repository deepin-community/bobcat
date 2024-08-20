
#include "ecdh.ih"

string ECDH::toHex(string const &data)
{
    string ret;

    for (unsigned char ch: data)
    {
        ret.push_back(s_digits[ch >> 4]);           // high nibble
        ret.push_back(s_digits[ch & 0xf]);          // low nibble
    }

    return ret;  
}
