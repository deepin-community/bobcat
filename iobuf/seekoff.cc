#include "iobuf.ih"

streambuf::pos_type IOBuf::seekoff(off_type offset, 
                                    ios::seekdir way, ios::openmode mode)
{
    return pSeekoff(offset, way, mode);
}
