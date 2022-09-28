//#define XERR
#include "csvtabdef.ih"

CSVTabDef::CSVTabDef(std::vector<FMT> &format, unsigned idx)
:
    d_idx(idx),
    d_format(format)
{}
