#include "datetime.ih"

string DateTime::rfc2822() const
{
    ostringstream out;

    out << s_day[d_tm.tm_wday] << ", " << setfill('0') << setw(2) <<
            d_tm.tm_mday << ' ' << s_month[d_tm.tm_mon] << ' ' <<
            1900 + d_tm.tm_year << ' ';

        // d_tm specifies the current time according to the current zone
        // assume this is UTC, then mktime returns the corresponding UTC time
        // if TZ is switched off.
    TM tm = d_tm;

    time_t difference = utcForZone("", tm) - d_utcSec;

    clockTime(out) << ' ' <<
            showpos <<
                setw(3) << internal <<   difference / 3600   <<
            noshowpos <<
                setw(2) << abs(difference) % 3600 / 60;

    return out.str();
}
