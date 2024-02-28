#include "argconfig.ih"

// no accept, no long options, no file

ArgConfig &ArgConfig::initialize(char const *optstring,
                             int argc, char **argv,
                             Comment cType, SearchCasing sType, Indices iType)
{
    if (s_argConfig)
        throw Exception{} << s_alreadyInitialized;

    s_argConfig.reset(new ArgConfig{ 0, optstring, 0, 0, argc, argv,
                                     cType, sType, iType }
                     );

    return *s_argConfig;
}
