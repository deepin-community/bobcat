#include "datetime.ih"

// static
string DateTime::Zone::dstConcatenate(
                            StringVector::const_iterator begin,
                            StringVector::const_iterator end)
{
    string ret;
    for (; begin != end; ++begin)
        ret += *begin + ' ';

    ret.pop_back();
    return ret;
}
