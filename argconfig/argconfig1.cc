#include "argconfig.ih"

ArgConfig::ArgConfig(int accept, char const *optstring,
                  LongOption const *const begin, LongOption const *const end, 
                  int argc, char **argv,
                  Comment cType, SearchCasing sType, Indices iType)
:
    Arg(accept, optstring, begin, end, argc, argv),
    ConfigFile(cType, sType, iType),
    d_ptr(new ArgConfig__(begin, end))
{}
