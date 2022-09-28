#include "configfile.ih"

ConfigFile_::ConfigFile_(string const &fname, Comment cType, 
                            SearchCasing sType, Indices iType)
:
    ConfigFile_(cType, sType, iType)
{
    open(fname);
}


ConfigFile::ConfigFile(string const &fname, Comment cType, 
                       SearchCasing sType, Indices iType)
:
    d_ptr(new ConfigFile_(fname, cType, sType, iType))
{}


