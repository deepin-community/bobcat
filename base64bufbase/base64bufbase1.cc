#include "base64bufbase.ih"

Base64BufBase::Base64BufBase(std::istream &in, size_t bufSize)
:   
    IFilterBuf(bufSize),
    d_in(in)
{}
