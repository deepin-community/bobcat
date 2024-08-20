inline bool ConfigFile__::finder(std::string const &haystack, std::string const &needle)
{
    return haystack.find(needle) != std::string::npos;
}
