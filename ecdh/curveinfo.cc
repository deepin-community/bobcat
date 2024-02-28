
#include "ecdh.ih"

// static
void ECDH::curveInfo(Table &tab, CurveInfo const &info)
{
    if (info.comment.find("Not suitable for ECDSA") == string::npos)
        tab << info.name << ' ' << 
            (info.comment.empty() ? " " : info.comment);
}
