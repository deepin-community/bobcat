#define XERR
#include "proc.ih"

void Proc::pipeSignal(bool on)          // true: SIG_DFL
{
    d_oBuf.warn(on);
    if (on)
        d_admin |= PIPE_SIGNAL;
    else
        d_admin &= ~PIPE_SIGNAL;
}
