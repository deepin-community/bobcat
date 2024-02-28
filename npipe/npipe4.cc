#include "npipe.ih"

NPipe::NPipe(bool initialize)
:
    Pipe(false)                     // initialize fds to -1
{
    if (initialize)
        reset();
}
