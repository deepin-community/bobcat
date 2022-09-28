//#define XERR
#include "csvtable.ih"

void CSVTable::streamFlags()
{
    d_flags = d_out->flags();               // original stream flags
    d_precision = d_out->precision();
    d_fillChar = d_out->fill();
    
    d_out->setf(ios::fixed, ios::floatfield);

}
