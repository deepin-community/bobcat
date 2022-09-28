#include "arg.ih"

void Arg__::versionHelp(void (*usage)(string const &progname), 
        char const *version, size_t minArgs, int helpFlag, 
        int versionFlag) const
{
    d_usage = usage;

    if (option(helpFlag))
    {
        usage(basename());
        throw 0;
    }

    if (option(versionFlag))
    {
        cout << basename() << " V" << version << '\n';
        throw 0;
    }

    if (nArgs() < minArgs)
    {
        usage(basename());
        throw 1;
    }
}

void Arg::versionHelp(void (*usage)(string const &progname), 
        char const *version, size_t minArgs, int helpFlag, 
        int versionFlag) const
{
    return d_ptr->versionHelp(usage, version, minArgs, helpFlag, versionFlag);
}

