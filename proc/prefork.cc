#define XERR
#include "proc.ih"

void Proc::preFork(IOMode mode, ProcType type, size_t bufSize, 
                   size_t timeLimit)
{
    d_child = RetPid{};                 // no child return value yet available
    d_timeLimit = timeLimit;
    rmBackticks();                      // rm backticks from d_command

                                        // save the default data in d_forkData
    d_forkData = { setBufSize(bufSize), setIOMode(mode), setProcType(type),
                    (d_admin & PIPE_SIGNAL) != 0 };

//xerr((d_forkData.pipeSignal ? "SIG_DFL" : "SIG_IGN"));

    signal(SIGPIPE, d_forkData.pipeSignal ? SIG_DFL : SIG_IGN);
}




