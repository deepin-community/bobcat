#include "extractorbase.ih"

void ExtractorBase::parentRedirections()
{
    reset(d_iChildOutPipe.readOnly(), IFdBuf::CLOSE_FD, d_bufSize);
}
