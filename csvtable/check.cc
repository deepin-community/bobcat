//#define XERR
#include "csvtable.ih"

void CSVTable::check(unsigned idx) const
{
    if (idx > d_format.size())
        throw Exception{} << "starting index (" << idx << 
                            ") exceeds available formats (" << 
                            d_format.size() << ')';
}
