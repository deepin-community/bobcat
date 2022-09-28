#include "datetime.ih"

string DateTime::rfc3339() const
{
    ostringstream out;

    out <<  setfill('0') <<
            1900 + d_tm.tm_year << '-' <<
            setw(2) << (d_tm.tm_mon + 1) << '-' <<
            setw(2) << d_tm.tm_mday << ' ';

    TM tm = d_tm;

    time_t difference = utcForZone("", tm) - d_utcSec;

    clockTime(out) << ' ' <<
                    showpos << setw(3) << internal << 
                               difference / 3600 << ':' << 
                    noshowpos << setw(2) << 
                               abs(difference) % 3600 / 60;
    return out.str();
}
