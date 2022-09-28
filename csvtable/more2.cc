//#define XERR
#include "csvtable.ih"

void CSVTable::more(std::string const &text, unsigned idx)
{
    CSVTabIns tabIns{ &d_idx, *d_out, d_format, checkInsertIdx(idx), 
                      d_sep, true };
    tabIns(text);
}
