inline std::string const &ECDH::curve() const
{
    return d_curveName;
}
        
inline std::string ECDH::privKey() const
{
    return "hex\n" + d_privKey;
}
        
inline std::string const &ECDH::pubKey() const
{
    return d_pubKey;
}
        
inline std::string const &ECDH::sharedKey() const
{
    return d_sharedKey;
}
        
inline std::ostream &operator<<(std::ostream &out, 
                                [[maybe_unused]] ECDH const &ecdh)
{
    return ECDH::showCurves(out);
}

