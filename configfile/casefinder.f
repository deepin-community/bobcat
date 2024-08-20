inline bool FBB::ConfigFile_::casefinder(std::string const &haystack,
                                         std::string const &needle)
{
    return strcasestr(haystack.c_str(), needle.c_str()) != 0;
}
