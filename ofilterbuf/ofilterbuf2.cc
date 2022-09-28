#include "ofilterbuf.ih"

OFilterBuf::OFilterBuf(std::string const &fname, openmode mode)
:
    d_dest(fname, mode),
    d_out(&d_dest)
{}
