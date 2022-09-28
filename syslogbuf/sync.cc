#include "syslogbuf.ih"

int SyslogBuf::sync()
{
    if (bufSize() != 0)
    {
        syslog(d_priority, "%s", buffer().c_str());
        buffer().clear();
        d_priority = d_orgPriority;
    }

    return 0;
}
