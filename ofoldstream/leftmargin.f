inline size_t OFoldStream::leftMargin(std::ostream const &os)
{
    return OFoldBuf::leftMargin(os.rdbuf());
}
