template <typename Tp>
OMutexStream::Out operator<<(OMutexStream const &mstr, Tp &&tp)
{
    OMutexStream::Out out{ mstr };
    out << std::forward<Tp>(tp);
    return out;
}
