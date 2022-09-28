//#define XERR
#include "csvtabins.ih"

unsigned CSVTabIns::width(FMT const &fmt) const
{
    return fmt.d_nCols == 1 ? fmt.d_width : width(d_idx, d_idx + fmt.d_nCols);
}
