#include "datetime.ih"

// static
int DateTime::Zone::add(string &dstSpec, string const &shift)
{
    if (dstSpec.empty())
        return 0;

    int ret = seconds(dstSpec);                 // dstSpec is the DST shift

    int dstSeconds = ret + seconds(shift);      // dst time needs the total
                                                // shift when dst is active

    char sign = dstSeconds < 0 ? '-' : '+';
    if (sign == '-')
        dstSeconds = -dstSeconds;

    dstSpec = sign + to_string(dstSeconds / 3600) + ':' +
                     to_string(dstSeconds % 60);

    return -ret;
}
