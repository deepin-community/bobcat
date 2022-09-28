#include "configfile.ih"

ConfigFile_::ConfigFile_(Comment cType, SearchCasing sType,
                       Indices iType)
:
    d_rmComment(cType == RemoveComment),
    d_caseSensitive(sType == SearchCaseSensitive),
    d_rawIndices(iType == StoreIndices ? 
                            &ConfigFile_::storeIndex 
                        :
                            &ConfigFile_::ignoreIndex)
{}

ConfigFile::ConfigFile(Comment cType, SearchCasing sType, Indices iType)
:
    d_ptr(new ConfigFile_(cType, sType, iType))
{}

