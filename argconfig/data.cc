#include "argconfig.ih"

unique_ptr<ArgConfig> ArgConfig::s_argConfig;

char const ArgConfig::s_alreadyInitialized[] =
                        "ArgConfig::initialize(): already initialized";
