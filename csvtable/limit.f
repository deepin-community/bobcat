//#define XERR
#include "csvtable.ih"

inline unsigned CSVTable::limit(unsigned idx) const
{
    return idx > d_format.size() ? d_format:size() : idx;
}
