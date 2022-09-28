#include "config.ih"

Config::const_iterator CF_Pimpl::findRE(
                                            const_iterator const &from) const 
{
    return 
        find_if(from, end(), 
            [&](CF_Line const &elem)
            {
                try
                {
                    d_pattern.match(elem.line());
                    return true;
                }
                catch (...)
                {
                    return false;
                }
            }
        );
}
