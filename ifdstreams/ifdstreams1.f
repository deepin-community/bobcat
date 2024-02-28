inline IFdStreamS::IFdStreamS(int fd, size_t n)
:
    IFdBufS(fd, n),
    std::istream(this)
{}
