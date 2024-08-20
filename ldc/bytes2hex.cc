#include "ldc.ih"

// static
void LDC::bytes2hex(string &arg)
{
                                        // ignore initial 0-characters
                                        // (non-essential cosmetics)
    if (size_t idx = arg.find_first_not_of('0', 0); idx != string::npos)
        arg.erase(0, idx);                      // keep a single 0-byte
    else
    {
        arg = string(1, 0);             // mere zeroes require no further
        return;                         // modifications
    }

    for (char &byte: arg)               // convert to binary hex bytes
        byte = isdigit(byte) ? byte - '0' : byte - 'a' + 10;

    reverse(arg.begin(), arg.end());    // least significant digit as binary
                                        // value is now at arg[0].
}
