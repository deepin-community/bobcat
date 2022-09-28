//#define XERR
#include "csvtable.ih"

void CSVTable::postStreamSwitch(int fillChar)
{
    streamFlags();

    d_out->fill(fillChar);
}
