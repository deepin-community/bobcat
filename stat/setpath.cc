#include "stat.ih"

bool Stat::setPath(int (*statFun)(char const *, stat *),
                   string const &name, string const &pathlist)
{
    if (name[0] == '/')
        return set(statFun, name);

    vector<string> element;
    String::split(&element, pathlist, ":");

    for 
    (
        vector<string>::iterator it = element.begin(); 
            it != element.end(); 
                ++it
    )
    {
        if (set(statFun, *it + "/" + name))
            return true;
    }

    return false;
}









