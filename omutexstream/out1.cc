#include "omutexstream.ih"

OMutexStream::Out::Out(OMutexStream const &mstr)
:
    std::ostream(mstr.d_out.rdbuf())
{
    s_mutex.lock();
}
