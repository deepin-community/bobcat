inline CF_Line const &CF_Pimpl::operator[](size_t idx) const
{
    return d_line[idx];
}

inline CF_Line const &Config::operator[](size_t idx) const
{
    return (*d_ptr)[idx];
}
