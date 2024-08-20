
#include "ecdh.ih"

//static 
string ECDH::toData(string const &hexString)
{
    if (hexString.length() & 1)
        throw Exception{} << "toData: invalid odd-sized hexString";

    string ret;

    for (auto iter = hexString.begin(), end = hexString.end(); iter != end; )
    {
        size_t hi = checkHex(*iter++);
        ret.push_back(hi << 4 | checkHex(*iter++));
    }

    return ret;
}
