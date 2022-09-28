//#define XERR
#include "csvtable.ih"

unsigned CSVTable::checkInsertIdx(unsigned idx)
{
    rowStreamReset();

    if (idx == ~0U)
        return d_idx;

    if (idx > d_format.size())
        return d_format.size();

    if (idx >= d_idx)
        return idx;

    throw Exception{} << "cannot insert values at column index " << idx << 
                         ": first available index is " << d_idx;
}
