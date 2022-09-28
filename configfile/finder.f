inline bool ConfigFile_::finder(string const &haystack, string const &needle)
{
    return haystack.find(needle) != string::npos;
}
