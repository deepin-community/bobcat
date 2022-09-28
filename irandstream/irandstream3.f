inline IRandStream::IRandStream(int min, int max, size_t seed)
:
    RandBuf(min, max, seed),
    std::istream(this)
{}
