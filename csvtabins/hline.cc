//#define XERR
#include "csvtabins.ih"

CSVTabIns &CSVTabIns::hline(FMT const &fmt)
{
    unsigned nCols = min(               // idx beyond the last col. to fill
                        d_idx + static_cast<size_t>(fmt.nCols()), 
                        d_format.size()
                     ) - d_idx;         // nCols: #columns to fill

    if (nCols == 0)
        return *this;

    char fill = d_out->fill();                      // set fill character
                                                    // write the line

    *d_out << setfill('-') << setw(width(d_idx, d_idx + nCols)) << '-';

    d_idx += nCols;

    if (d_idx < d_format.size())                    // sep. unless the last
        *d_out << d_sep;                            // column

    *d_out << setfill(fill);                        // reset the fill char.

    return *this;
}
