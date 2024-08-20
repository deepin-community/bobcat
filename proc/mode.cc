#include "proc.ih"

std::string Proc::mode() const
{
    string ret;

    if (d_mode == NONE)
        return ret = "NONE";

    if (d_mode & REPLACE)
        return ret += "REPLACE";

    if (d_mode & CIN)
        ret += "CIN ";

    if (d_mode & COUT)
        ret += "COUT ";

    if (d_mode & CERR)
        ret += "CERR ";

    if (d_mode & IGNORE_COUT)
        ret += "IGNORE_COUT ";

    if (d_mode & IGNORE_CERR)
        ret += "IGNORE_CERR ";

    if (d_mode & MERGE_COUT_CERR)
        ret += "MERGE_COUT_CERR ";

    ret.pop_back();

    return ret;
}





