//#define XERR
#include "csvtabins.ih"

unsigned CSVTabIns::width(unsigned begin, unsigned end) const
{
    if (end > d_format.size())
        end = d_format.size();
                                                        // total width of in-
    unsigned ret = (end - begin - 1) * d_sep.length();  // between separators

    for (; begin != end; ++begin)
        ret += d_format[begin].width();                 // add field widths

    return ret;
}
