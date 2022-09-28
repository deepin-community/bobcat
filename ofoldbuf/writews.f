inline void OFoldBuf::writeWs() const
{
    out().write(d_ws.data(), d_ws.length());
}
