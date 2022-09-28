#include "syslogbuf.ih"

void SyslogBuf::eoi_()
{
    sync();   
    closelog();                     // syslog.h
}
