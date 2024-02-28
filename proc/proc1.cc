#include "proc.ih"

Proc::Proc(string const &cmd, IOMode mode, ProcType type, size_t bufSize, 
           size_t timeLimit, bool pipeSig)
:
    d_ptr(0),                   // for now: unused.
    d_admin(LOCAL_PIPES),
    d_cmd(cmd),
    d_err(&cerr),
    d_in(0),
    d_out(&cout),
    d_pipesPtr(0),         //new vector<Pipe>(3)),
    d_timeLimit(timeLimit),
    d_timerSem(0),
    d_id(++s_id)
{
    pipeSignal(pipeSig);
    setBufSize(bufSize);
    setProcType(type);
    setIOMode(mode);
    rdbuf(&d_oBuf);
}





