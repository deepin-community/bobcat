#include "syslogbuf.ih"

SyslogBuf::SyslogBuf(std::string const &ident, 
                     Priority priority, Facility facility, int option)
:
    d_priority(priority),
    d_orgPriority(priority)
{
    reset(ident, facility, option);
    setp();                             // no buffer yet
}













