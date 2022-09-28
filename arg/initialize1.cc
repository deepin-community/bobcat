#include "arg.ih"

Arg &Arg::initialize(char const *optstring, int argc, char **argv)
{
    if (s_arg)
        throw Exception{} << s_alreadyInitialized;

    s_arg = new Arg(0, optstring, 0, 0, argc, argv);

    return *s_arg;
}
