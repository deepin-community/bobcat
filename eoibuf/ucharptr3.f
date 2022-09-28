// static
inline unsigned char *EoiBuf::ucharPtr(std::string &str)
{
    return reinterpret_cast<unsigned char *>(&str[0]);
}
