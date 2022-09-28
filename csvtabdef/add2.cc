//#define XERR
#include "csvtabdef.ih"

void CSVTabDef::add(unsigned width)
{
    if (d_idx == d_format.size())                   // new format field
        d_format.push_back(                         // R-aligned, 'width' 
                    FMT{ FMT::RIGHT, width, ~0U }); // characters

                                        // keep the format, enlarge the width
    else if (FMT &fmt = d_format[d_idx];  width > fmt.d_width)
        fmt.d_width = width;

    ++d_idx;
}
