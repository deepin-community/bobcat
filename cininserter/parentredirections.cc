#include "cininserter.ih"

void CinInserter::parentRedirections()
{
    reset(d_oChildInPipe.writeOnly(), OFdBuf::CLOSE_FD, d_bufSize);
//    open(d_oChildInPipe.writeOnly(), d_bufSize);
}
