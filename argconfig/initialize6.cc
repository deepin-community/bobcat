#include "argconfig.ih"

// accept, no long options, file, 

// static
ArgConfig &ArgConfig::initialize(int accept, char const *optstring,  
                            int argc, char **argv,
                            std::string const &fname,
                            Comment cType, SearchCasing sType, Indices iType)
{
    if (s_argconfig)
        throw Exception{} << s_alreadyInitialized;

    s_argconfig = new ArgConfig(accept, optstring, 
                            0, 0,
                            argc, argv, 
                            fname,
                            cType, sType, iType);

    return *s_argconfig;
}
