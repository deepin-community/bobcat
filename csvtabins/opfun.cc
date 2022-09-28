//#define XERR
#include "csvtabins.ih"

void CSVTabIns::operator()(string const &text)
{
    for (auto const &pair: String::split(text, String::STR, ","))
        insert(String::trim(pair.first));               // insert1.f
}
