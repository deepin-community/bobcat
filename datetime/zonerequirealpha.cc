#include "datetime.ih"

void DateTime::Zone::requireAlpha(string const &name)
{
    if (
        name.length() < 3 
        or
        find_if(name.begin(), name.end(), 
            [&](char ch)
            {
                return not isalpha(ch);
            }
        ) != name.end()
    )
        throw Exception{ 1 } << "Zone names (`" << name << 
                                    "') must consist of at least 3 letters";
}
