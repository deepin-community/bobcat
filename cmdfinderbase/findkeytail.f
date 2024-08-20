inline std::string ConfigFile__::findKeyTail(std::string const &keyPattern, size_t count)
{
    return searchFor("^\\s*" + keyPattern + "\\s+(.*)\\s*$", count);
}
