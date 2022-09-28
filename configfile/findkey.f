inline string ConfigFile_::findKey(string const &keyPattern, size_t count)
{
    return searchFor("^\\s*" + keyPattern + "\\s+(\\S+)", count);
}
