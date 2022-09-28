//#define XERR
#include "config.ih"

string CF_Line::value() const
{
    size_t pos = tailPos();

    string ret;

    if (pos != string::npos)
        ret = d_line.substr(pos, next(pos) - pos);

    return ret;
}
