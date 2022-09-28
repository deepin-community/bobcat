#include "arg.ih"

    // accept: use -'accept' instead of --
    // opstring[0] == '+': accept undefined options

Arg::Arg(int accept, char const *optstring, 
         LongOption const * const begin, LongOption const * const end,
         int argc, char **argv)
:
    d_ptr(new Arg__(accept, optstring, begin, end, argc, argv))
{
    d_ptr->verify();
}
