//#define XERR
#include "csvtable.ih"

CSVTabDef CSVTable::fmt(unsigned idx)
{
    check(idx);
    return CSVTabDef{ d_format, idx };
}
