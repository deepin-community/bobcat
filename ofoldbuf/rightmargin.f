inline size_t OFoldBuf::rightMargin(std::streambuf const *buffer)
{
    return (*findOFoldBuf(buffer))->d_rightMargin;
}
