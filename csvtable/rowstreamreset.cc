//#define XERR
#include "csvtable.ih"

void CSVTable::rowStreamReset()
{
    if (d_idx == 0)
        streamReset();
}
