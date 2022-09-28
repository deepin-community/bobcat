//#define XERR
#include "csvtable.ih"

CSVTable::CSVTable(string const &fname, string const &sep, ios::openmode mode)
:
    d_strPtr(new ofstream(Exception::factory<ofstream>(fname, mode))),
    d_out(d_strPtr.get()),
    d_sep(sep),

    d_idx(0)
{
    streamFlags();
}
