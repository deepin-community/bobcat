//#define XERR
#include "fmt.ih"

    // handles, e.g., join(3, FMT::left, precision)
    // when inserting width in fact is precision

FMT FBB::join(unsigned nCols, FMT::Align align, unsigned precision)
{
    FMT::lrcFun(align);             // ensure the correct alignment request

    return { align, precision, 0, nCols };
}

