//#define XERR
#include "csvtabins.ih"

CSVTabIns::~CSVTabIns()
{
    if (d_more)
    {
        *d_tabIdx = d_idx;
        return;
    }

    for (; d_idx != d_format.size(); )  // fill remaining columns with 
        insert(' ');                    // spaces

    *d_out << '\n';                     // then end the row
    *d_tabIdx = 0;                      // and back to column 0
}
