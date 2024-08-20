inline void FBB::OFoldBuf::writeWs() const
{
    out().write(d_ws.data(), d_ws.length());
}
