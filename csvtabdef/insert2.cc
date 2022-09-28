#define XERR
#include "csvtabdef.ih"

CSVTabDef &CSVTabDef::insert(FMT const &fmt)
{
    if (fmt.d_nCols != 1)
        throw Exception{} << 
            "table column definitions cannot span multiple columns (col. " <<
            d_idx << ')';

    if (FMT::lrcFun(fmt.d_align) == 0)
        throw Exception{} << 
            "table column alignments must be "
                "left, right or center (col. " << d_idx << ')';

    if (d_idx == d_format.size())
        d_format.push_back(fmt);
    else
    {
                                                // keep the larger width
        unsigned width = max(d_format[d_idx].d_width, fmt.d_width);
        (d_format[d_idx] = fmt).d_width = width;
    }

    ++d_idx;

    return *this;
}
