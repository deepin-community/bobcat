//#define XERR
#include "csvtable.ih"

void CSVTable::fmt(string const &fields, unsigned idx)
{
    check(idx);

    CSVTabDef tabDef{ d_format, idx };
    tabDef.split(fields);
}
