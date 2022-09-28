#include "arg.ih"

char const **Arg__::argPointers() const
{
    if (!d_argPointer)
        d_argPointer = String::argv(d_argv);

    return d_argPointer;
}

