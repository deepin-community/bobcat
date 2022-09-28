//#define XERR
#include "csvtable.ih"

CSVTable::CSVTable(ostream &out, string const &sep)
:
    d_out(&out),
    d_sep(sep),

    d_idx(0)
{
    streamFlags();
}
