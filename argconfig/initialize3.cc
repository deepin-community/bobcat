#include "argconfig.ih"

// no accept, long options, no file, 

// static
ArgConfig &ArgConfig::initialize(char const *optstring,
                LongOption const *begin, LongOption const *const end,
                int argc, char **argv,
                Comment cType, SearchCasing sType, Indices iType)
{
    if (s_argconfig)
        throw Exception{} << s_alreadyInitialized;

    s_argconfig = new ArgConfig(0, optstring, 
                            begin, end,
                            argc, argv, 
                            cType, sType, iType);

    return *s_argconfig;
}
