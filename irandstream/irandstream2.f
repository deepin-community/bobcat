inline IRandStream::IRandStream(int min, int max)
:
    RandBuf(min, max, 1),
    std::istream(this)
{}
