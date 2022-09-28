#include "configfile.ih"

ConfigFile::ConfigFile(ConfigFile const &rhs)
:
    d_ptr(new ConfigFile_(*rhs.d_ptr))
{}
