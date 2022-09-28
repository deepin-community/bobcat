inline OMutexStream::Out OMutexStream::ostream() const
{
    return OMutexStream::Out{ *this };
}
