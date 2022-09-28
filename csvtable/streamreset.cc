//#define XERR
#include "csvtable.ih"

void CSVTable::streamReset()
{
    d_out->setf(d_flags);                   // reset *d_out to its original
    d_out->precision(d_precision);          // fmt specs
    d_out->fill(d_fillChar);
}
