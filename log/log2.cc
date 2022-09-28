#include "log.ih"

Log::Log(ostream &out, char const *delim)
:
    LogBuf(out, TIMESTAMPS, true, delim),
    ostream(this)
{
    init();
}
