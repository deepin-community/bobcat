inline void FBB::OFoldBuf::writeNonWs() const
{
    out().write(d_nonWs.data(), d_nonWs.length());
}
