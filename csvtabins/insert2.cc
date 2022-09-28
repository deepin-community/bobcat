//#define XERR
#include "csvtabins.ih"

    // fmt insertion:
    //     hline: inserts hline unless beyond the last column
    //     
    //     left/right/center formatting:
    //          beyond the last column: 
    //              at LEFT: align left, otherwise right
    //              set precision unless d_size (acting as precision) == ~0U
    //              d_nCols is ignored
    //          within the table:
    //              set extraFMT with d_precision: fmt.d_width
    //                                d_wdith: width(fmt)

CSVTabIns &CSVTabIns::insert(FMT const &fmt)
{
    if (fmt.align() == FMT::HLINE)          // fmt contains total width 
        hline(fmt);                         // and nCols used by the hline
    else if (d_idx == d_format.size())      // ignore beyond the last column
    {
        if (fmt.d_width != ~0U)
            d_out->precision(fmt.d_width);

        *d_out << (fmt.align() == FMT::LEFT ? std::left : std::right);
    }
    else
    {
        d_useExtraFMT = true;
        d_extraFMT = fmt;
                                                // when inserting d_width is
        d_extraFMT.d_precision = fmt.d_width;   // the precision

                                                        // and use d_format's
        d_extraFMT.d_width = d_format[d_idx].d_width;   // width

        d_extraFMT.d_width = width(d_extraFMT); // compute the width
    }

    return *this;
}
