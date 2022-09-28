inline unsigned char *EoiBuf::ucharPtr()
{
    return reinterpret_cast<unsigned char *>(&d_buffer[0]);
}
