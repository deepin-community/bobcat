//#define XERR
#include "csvtable.ih"

CSVTabIns CSVTable::more(unsigned idx)
{
    return CSVTabIns{ &d_idx, *d_out, d_format, checkInsertIdx(idx), 
                      d_sep, true };
}
