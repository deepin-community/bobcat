#include "ohexbuf.ih"

string OHexBuf::text2bin(string const &in)
{
    string ret;

    for (size_t idx = 0, end = in.length(); idx != end; idx += 2)
        ret += stoul(in.substr(idx, 2), 0, 16);

    return ret;
}
