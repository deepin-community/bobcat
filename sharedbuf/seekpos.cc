#include "sharedbuf.ih"

ios::pos_type SharedBuf::seekpos(ios::pos_type offset, 
                                       ios::openmode mode)
{
    return seekoff(offset, ios::beg, mode);
}
