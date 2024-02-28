inline unsigned char *SymCryptBase::uOutBuf()
{
    return reinterpret_cast<unsigned char *>(d_outBuf.get());
}
