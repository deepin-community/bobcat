//#define XERR
#include "fmt.ih"

FMT::FMT(Align align, unsigned width, unsigned precision, unsigned nCols)
:
    d_align(align),
    d_width(width == 0 ? 1 : width),
    d_precision(precision),
    d_nCols(nCols == 0 ? 1 : nCols)
{}
