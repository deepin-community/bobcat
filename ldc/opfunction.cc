#include "ldc.ih"

#include <iostream>
string LDC::operator()(size_t power, char sep) const
{
    string ret;

    if (power <= 1)
        return ret = d_converted;

    size_t end = d_converted.length();

    size_t begin = end % power;
    if (begin == 0)
        begin += power;

    ret += d_converted.substr(0, begin);

    for (; begin != end; begin += power)
        ret += sep + d_converted.substr(begin, power);

    return ret;
}
