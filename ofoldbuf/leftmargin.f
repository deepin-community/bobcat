inline size_t FBB::OFoldBuf::leftMargin(std::streambuf const *buffer)
{
    return (*findOFoldBuf(buffer))->d_indent;
}
