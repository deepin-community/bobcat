inline void OFoldBuf::writeNonWs() const
{
    out().write(d_nonWs.data(), d_nonWs.length());
}
