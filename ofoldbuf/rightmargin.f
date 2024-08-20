inline size_t FBB::OFoldBuf::rightMargin(std::streambuf const *buffer)
{
    return (*findOFoldBuf(buffer))->d_rightMargin;
}
