inline std::string FBB::ConfigFile_::findKey(std::string const &keyPattern, 
                                        size_t count)
{
    return searchFor("^\\s*" + keyPattern + "\\s+(\\S+)", count);
}
