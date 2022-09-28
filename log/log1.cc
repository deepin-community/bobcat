#include "log.ih"

Log::Log()
:
    LogBuf(TIMESTAMPS, false, " "),
    ostream(this)
{
    init();
}
