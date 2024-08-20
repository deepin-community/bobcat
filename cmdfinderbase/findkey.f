inline std::string ConfigFile__::findKey(std::string const &keyPattern, size_t count)
{
    return searchFor("^\\s*" + keyPattern + "\\s+(\\S+)", count);
}
