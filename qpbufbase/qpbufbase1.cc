#include "qpbufbase.ih"

QPBufBase::QPBufBase(std::istream &in, size_t bufSize)
:   
    IFilterBuf(bufSize),
    d_in(in)
{}
