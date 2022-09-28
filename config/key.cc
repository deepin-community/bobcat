//#define XERR
#include "config.ih"

string CF_Line::key() const
{
    string ret;

    if (size_t pos = next(0); pos != string::npos)  // key available
        ret = d_line.substr(0, pos);

    return ret;
}
