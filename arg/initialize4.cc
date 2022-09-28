#include "arg.ih"

Arg &Arg::initialize(int accept, char const *optstring,
                LongOption const *const begin, 
                LongOption const *const end, 
                int argc, char **argv)
{
    if (s_arg)
        throw Exception{} << s_alreadyInitialized;

    s_arg = new Arg(accept, optstring, begin, end, argc, argv);

    return *s_arg;
}
