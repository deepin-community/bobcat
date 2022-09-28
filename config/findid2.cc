#include "config.ih"

Config::const_iterator CF_Pimpl::findID(
                        string const &id, const_iterator const &from) const 
{
    auto strIter = find_if(id.begin(), id.end(),       // find 1st non-ID char
        [&](int ch)
        {
            return not idChar(ch);
        }
    );
                                                // use id's ID-chars until 
    string const &key =                         // the first non-ID char
                strIter == id.end()? id : id.substr(0, strIter - id.begin());

    return 
        find_if(from, end(), 
            [&](CF_Line const &elem)
            {                                       // the key must start at
                return elem.line().find(key) == 0          // line[0]
                       and                          // and no ID char next
                       not idChar(elem.line()[key.length()]);
            }
        );
}
