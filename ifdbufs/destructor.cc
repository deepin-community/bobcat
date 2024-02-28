#include "ifdbufs.ih"

IFdBufS::~IFdBufS()
{
    cleanup(mode());
}
