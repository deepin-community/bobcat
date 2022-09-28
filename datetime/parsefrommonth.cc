#include "datetime.ih"

// Day name already read:
//
//        Mon Dec 3 13:29:11 2018           spec. #1: d_type UTC: UTC time,
//                                                    LOCALTIME: local time
//  or:
//        Mon Dec 3 13:29:11 CET 2018       spec. #2,

void DateTime::Parse::fromMonth()
{
    string month;
    string zoneOrYear;
    char sep;

    if (                                    // get all fields through tz-name
            not (                           // or year
            d_in >> month >> d_tm.tm_mday >>
                    d_tm.tm_hour >> sep >> d_tm.tm_min >> sep >>
                    d_tm.tm_sec >> zoneOrYear
            )
    )
        throw 1;                            // format error -> iniParse()

    setMonth(month);                        // throws on month error

    if (isdigit(zoneOrYear[0]))             // got a year: spec. #1
    {
        d_tm.tm_year = stoul(zoneOrYear);
        d_format = 1;
        return;
    }

                                            // spec #2:
    if (not (d_in >> d_tm.tm_year))         // "Mon Dec 3 13:29:11 CET 2018"
        throw 1;

    d_zoneName = zoneOrYear;
    d_format = 2;
}
