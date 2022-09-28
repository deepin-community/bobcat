inline Config::const_iterator Config::findID(
                        std::string const &id, const_iterator from) const 
{
    return d_ptr->findID(id, from);
}

inline Config::const_iterator Config::findID(
                                             std::string const &id) const
{
    return findID(id, begin());
}
