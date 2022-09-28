#include "omutexstream.ih"

OMutexStream::Out::~Out()
{
    s_mutex.unlock();
}
