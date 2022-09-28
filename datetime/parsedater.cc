#include "datetime.ih"

    // format type 3:
    //  Mon, 03 Dec 2018 13:29:11 +0100     `Mon,' has already been read.

void DateTime::Parse::dateR()
{
    char sign;
    int zoneMinutes;
    string month;
    char sep;

    if (
            not (
                d_in >> d_tm.tm_mday >> month >> d_tm.tm_year >>
                        d_tm.tm_hour >> sep >> d_tm.tm_min >> sep >>
                        d_tm.tm_sec >> sign >> zoneMinutes
            )
    )
        throw 1;                                // format error

    setMonth(month);                            // throws on month-error

    setZoneShift(sign == '-', 0, zoneMinutes / 100 * 60 + zoneMinutes % 100);

    d_format = 3;
}


