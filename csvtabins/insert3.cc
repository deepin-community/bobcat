//#define XERR
#include "csvtabins.ih"

CSVTabIns &CSVTabIns::insert(FMT::Align align)  
{
    FMT::FMTFun funPtr = FMT::lrcFun(align);

    return 
        insert (
            (*funPtr)(
                d_format[d_idx].d_width,        // width becomes precision
                ~0U                             // 2nd argument not used
            )
        );     
}
