//#define XERR
#include "fmt.ih"

// static
FMT::FMTFun FMT::lrcFun(Align align)
{
    FMTFun ret = s_lrcFun[align];

    if (ret == 0)
        throw Exception{} << 
                "Alignment must be FMT::LEFT, FMT::RIGHT, or FMT::CENTER";

    return ret;
}
