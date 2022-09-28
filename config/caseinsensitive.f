//static
inline bool CF_Pimpl::caseInsensitive(std::string const &lhs, 
                                             std::string const &rhs)
{
    return caseSensitive(String::lc(lhs), rhs);
}

