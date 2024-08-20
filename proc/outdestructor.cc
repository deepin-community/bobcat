#include "proc.ih"

Proc::Out::~Out()
{
    if (d_alloc)
        delete d_stream;                // flushes the stream
    else
        d_stream->flush();
}

