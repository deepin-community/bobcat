inline void IFdBufS::reset(int fd, size_t size)
{
    reset(fd, mode(), size);
}
