//#define XERR
#include "csvtable.ih"

void CSVTable::stream(std::ostream &out)
{
    int fillChar = preStreamSwitch();

    d_out = &out;                           // switch stream

    postStreamSwitch(fillChar);
}
