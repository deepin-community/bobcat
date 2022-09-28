#include "syslogbuf.ih"

Priority SyslogBuf::setPriority(Priority priority)
{
    Priority old = d_priority;
    d_priority = priority;
    return old;
}
