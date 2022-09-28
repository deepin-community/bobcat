#include "syslogstream.ih"

ostream &SyslogStream::setPriority(ostream &str, Priority value)
{
    SyslogBuf *sb = dynamic_cast<SyslogBuf *>(str.rdbuf());

    if (sb)
        sb->setPriority(value);

    return str;
}
