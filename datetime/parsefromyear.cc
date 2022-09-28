#include "datetime.ih"

    // expects type 4: 2018-12-03 13:29:11+01:00, where d_tm.tm_year (2018)
    // has already been read.

    // spec. 4: 2018-12-03 13:29:11+01:00

void DateTime::Parse::fromYear()
{
    char sep;
    char sign;
    int hours;
    int minutes;

    if (not (
        d_in >> sep >>                      //  -
            d_tm.tm_mon >> sep >>           // 12 -
            d_tm.tm_mday >>                 // 03
            d_tm.tm_hour >> sep >>          // 13 :
            d_tm.tm_min >> sep >>           // 29 :
            d_tm.tm_sec >>                  // 11
            sign >> hours >> sep >> minutes // + 01 : 00
        )
    )
        throw 1;                            // caught by the constructor

    --d_tm.tm_mon;                          // tm_mon: 0-based

    setZoneShift(sign == '-', hours, minutes);

    d_format = 4;
}





