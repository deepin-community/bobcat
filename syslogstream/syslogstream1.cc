#include "syslogstream.ih"

SyslogStream::SyslogStream(string const &ident, Priority priority, 
                            Facility facility, int option)
:
    SyslogBuf(ident, priority, facility, option),
    std::ostream(this)
{}
