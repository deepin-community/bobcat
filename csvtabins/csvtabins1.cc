//#define XERR
#include "csvtabins.ih"

CSVTabIns::CSVTabIns(unsigned *tabIdx, ostream &out, 
                     vector<FMT> const &format, 
                     unsigned startIdx, string const &sep, bool more)
:
    d_tabIdx(tabIdx),
    d_idx(*tabIdx),
    d_out(&out),
    d_format(format),
    d_sep(sep),
    d_useExtraFMT(false),
    d_more(more)
{
    for (unsigned fill = startIdx - d_idx; fill-- != 0; )
        insert(' ');
}

