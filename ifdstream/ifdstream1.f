inline IFdStream::IFdStream(int fd, size_t n)
:
    IFdBuf(fd, n),
    std::istream(this)
{}
