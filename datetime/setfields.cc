#include "datetime.ih"

void DateTime::setFields(TM const &src, TimeFields fields)
{
    if (fields & SECONDS)
        d_tm.tm_sec = src.tm_sec;

    if (fields & MINUTES)
        d_tm.tm_min = src.tm_min;

    if (fields & HOURS)
        d_tm.tm_hour = src.tm_hour;

    if (fields & MONTHDAY)
        d_tm.tm_mday = src.tm_mday;

    if (fields & MONTH)
        d_tm.tm_mon = src.tm_mon;

    if (fields & YEAR)
        d_tm.tm_year = src.tm_year - 1900;

    d_utcSec = utcForZone(zone().spec(), d_tm);

    assignTM();
}


