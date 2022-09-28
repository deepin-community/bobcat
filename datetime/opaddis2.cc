#include "datetime.ih"

DateTime &DateTime::operator+=(TM const &src)
{
    d_tm.tm_sec  += src.tm_sec;
    d_tm.tm_min  += src.tm_min;
    d_tm.tm_hour += src.tm_hour;
    d_tm.tm_mday += src.tm_mday;
    d_tm.tm_mon  += src.tm_mon;
    d_tm.tm_year += src.tm_year;

    d_utcSec = utcForZone(zone().spec(), d_tm);
    assignTM();

    return *this;
}
