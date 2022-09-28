#include "syslogbuf.ih"

void SyslogBuf::reset(string const &ident, Facility facility, int option)
{
    d_ident = ident;
    openlog(d_ident.c_str(), option, facility);
}
