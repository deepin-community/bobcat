inline std::string const &EncryptBuf::iv() const
{
    static std::string ret;

    return ret;
}
