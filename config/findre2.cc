#include "config.ih"

Config::const_iterator CF_Pimpl::findRE(
                        string const &re, const_iterator const &from) const 
{
    d_pattern.setPattern(re, d_caseSensitive);

    return findRE(from);
}
