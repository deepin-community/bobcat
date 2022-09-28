//#define XERR
#include "csvtable.ih"

void CSVTable::stream(ofstream &&tmp)
{
    int fillChar = preStreamSwitch();

    d_strPtr = unique_ptr<std::ofstream>{ new ofstream(move(tmp)) };
    d_out = d_strPtr.get();

    postStreamSwitch(fillChar);
}
