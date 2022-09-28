#include "configfile.ih"

ConfigFile::ConfigFile(ConfigFile &&tmp)
:
    d_ptr( new ConfigFile_(move(*tmp.d_ptr) ))
{}
