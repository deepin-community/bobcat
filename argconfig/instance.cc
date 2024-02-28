#include "argconfig.ih"

ArgConfig &ArgConfig::instance()
{
    if (not s_argConfig)
        throw Exception{} << "ArgConfig::instance(): not yet initialized";

    return *s_argConfig;
}
