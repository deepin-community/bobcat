#include "syslogbuf.ih"

void SyslogBuf::reset(std::string const &ident, 
                     Priority priority, Facility facility, int option)
{
    eoi();
    d_orgPriority = d_priority = priority;

    reset(ident, facility, option);
}
