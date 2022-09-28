#include "iobuf.ih"

int IOBuf::sync()
{        
    d_out->flush();
    return not d_out->good();
}
