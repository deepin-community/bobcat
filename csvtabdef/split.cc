//#define XERR
#include "csvtabdef.ih"

void CSVTabDef::split(string const &fields)
{
    for (auto const &pair: String::split(fields, String::STR, ","))
        add(pair.first);                    // add trimmed fields
}
