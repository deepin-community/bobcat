inline Config::const_iterator Config::findRE(
                    std::string const &id, const_iterator const &from) const 
{
    return d_ptr->findRE(id, from);
}

inline Config::const_iterator Config::findRE(
                                             std::string const &id) const
{
    return findRE(id, begin());
}
