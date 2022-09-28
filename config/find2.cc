#include "config.ih"

Config::const_iterator CF_Pimpl::find(string const &needle,
                                             const_iterator const &from) const
{
    bool (*finder)(std::string const &haystack,
                     std::string const &needle);

    string const *needlePtr;
    string needleLow;

    if (d_caseSensitive)
    {
        needlePtr = &needle;
        finder = caseSensitive;
    }
    else
    {
        needleLow = String::lc(needle);
        needlePtr = &needleLow;
        finder = caseInsensitive;
    }

    return find_if(
                from, end(), 
                [&](CF_Line const &haystack)
                {
                    return finder(haystack.line(), *needlePtr);
                }
            );
}

