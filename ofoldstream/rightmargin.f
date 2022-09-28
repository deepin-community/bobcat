inline size_t OFoldStream::rightMargin(std::ostream const &os)
{
    return OFoldBuf::rightMargin(os.rdbuf());
}
