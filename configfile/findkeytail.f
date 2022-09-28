inline std::string ConfigFile_::findKeyTail(std::string const &keyPattern, 
                                            size_t count)
{
    return searchFor("^\\s*" + keyPattern + "\\s+(.*)\\s*$", count);
}
