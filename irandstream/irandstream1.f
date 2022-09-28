inline IRandStream::IRandStream(int max)
:
    RandBuf(1, max, 1),
    std::istream(this)
{}
