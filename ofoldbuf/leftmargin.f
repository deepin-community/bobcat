inline size_t OFoldBuf::leftMargin(std::streambuf const *buffer)
{
    return (*findOFoldBuf(buffer))->d_indent;
}
