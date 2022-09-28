#include "datetime.ih"

ostream &DateTime::clockTime(ostream &out) const
{
    return
        out <<  setw(2) << d_tm.tm_hour << ':' <<
                setw(2) << d_tm.tm_min << ':' <<
                setw(2) << d_tm.tm_sec;
}
