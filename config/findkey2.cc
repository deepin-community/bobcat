#include "config.ih"

Config::const_iterator CF_Pimpl::findKey(
                        string const &key, const_iterator const &from) const 
{
    d_pattern.setPattern("^\\s*" + key + "\\s+(\\S+)", d_caseSensitive);

    return findRE(from);
}
