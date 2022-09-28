#include "syslogbuf.ih"

// override

streamsize SyslogBuf::xsputn(char const *buf, streamsize nChars)
{
    buffer().append(buf, nChars);
    return nChars;
}
