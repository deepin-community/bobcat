#include "iobuf.ih"

IOBuf::pos_type IOBuf::seekpos(pos_type offset, 
                                           ios::openmode mode)
{
    return pSeekpos(offset, mode);
}

