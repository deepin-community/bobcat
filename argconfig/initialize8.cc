#include "argconfig.ih"

// accept, long options, file,
// static

ArgConfig &ArgConfig::initialize(int accept, char const *optstring,
            LongOption const *begin, LongOption const *const end,
            int argc, char **argv,
            string const &fname,
            Comment cType, SearchCasing sType, Indices iType)
{
    if (s_argConfig)
        throw Exception{} << s_alreadyInitialized;

    s_argConfig.reset(new ArgConfig{ accept, optstring,
                                     begin, end,
                                     argc, argv,
                                     fname,
                                     cType, sType, iType }
                     );

    return *s_argConfig;
}
