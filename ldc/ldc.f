inline std::string const &LDC::str() const
{
    return d_converted;
}

inline std::ostream &operator<<(std::ostream &out, LDC const &ldc)
{
    return out << ldc.str();
}
