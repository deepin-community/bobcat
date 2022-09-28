inline OFdStream::OFdStream(int fd, size_t n)
:
    OFdBuf(fd, n),
    std::ostream(this)
{}
