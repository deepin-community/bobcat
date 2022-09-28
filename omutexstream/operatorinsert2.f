template <typename Ret>
OMutexStream::Out operator<<(OMutexStream const &mstr, Ret &(*manip)(Ret &os))
{
    OMutexStream::Out out{ mstr };
    out << manip;
    return out;
}
