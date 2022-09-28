inline CF_Pimpl::const_iterator CF_Pimpl::begin() const
{
    return d_line.begin();
}

inline Config::const_iterator Config::begin() const
{
    return d_ptr->begin();
}
   
