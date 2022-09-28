//static
inline bool CF_Pimpl::caseSensitive(std::string const &haystack, 
                                           std::string const &needle)
{
    return haystack.find(needle) != std::string::npos;
}

