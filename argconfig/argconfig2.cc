#include "argconfig.ih"

ArgConfig::ArgConfig(int accept, char const *optstring, 
                   LongOption const *begin, LongOption const *const end, 
                   int argc, char **argv, 
                   string const &fname,
                   Comment cType, SearchCasing sType, Indices iType)
:
    Arg(accept, optstring, begin, end, argc, argv),
    ConfigFile(fname, cType, sType, iType),
    d_ptr(new ArgConfig__(begin, end))
{}


