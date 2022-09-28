//#define XERR
#include "csvtable.ih"

void CSVTable::stream(string const &fname, ios::openmode mode)
{
    int fillChar = preStreamSwitch();

    d_strPtr = unique_ptr<std::ofstream>{ 
                    new ofstream(Exception::factory<ofstream>(fname, mode))
                };
    d_out = d_strPtr.get();

    postStreamSwitch(fillChar);
}
