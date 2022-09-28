//#define XERR
#include "config.ih"

string CF_Line::tail() const
{
    size_t pos = tailPos();

    string ret;

    if (pos != string::npos)                // there is a tail
        ret = d_line.substr(pos);           // assign it to ret

    return ret;
}
