#include "logbuf.ih"

int LogBuf::sync()
{
    d_stream->flush();
    return 0;
}
