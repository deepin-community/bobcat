//#define XERR
#include "csvtable.ih"

CSVTable::CSVTable(ofstream &&tmp, string const &sep)
:
    d_strPtr(new ofstream(move(tmp))),
    d_out(d_strPtr.get()),
    d_sep(sep),

    d_idx(0)
{
    streamFlags();
}
