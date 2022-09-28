#include "syslogbuf.ih"

Priority SyslogBuf::setDefaultPriority(Priority priority)
{
    Priority old = d_orgPriority;
    d_orgPriority = priority;
    return old;
}
