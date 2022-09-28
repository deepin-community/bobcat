inline unsigned char const *EoiBuf::ucharPtr() const
{
    return reinterpret_cast<unsigned char const *>(&d_buffer[0]);
}
