#include "datetime.ih"

// tm specifies UTC when type == UTC, and the computer's localtime if 
// type == LOCALTIME. The tm_year field specifies the calendar year, so
// 2019 or comparable.
//
// tm's wday, yday and isdst are ignored

DateTime::DateTime(TM const &tm, TimeType type)
:
    DateTime(type)                 // initialize UTC or LOCALTIME zone
{
    d_tm = tm;
    d_tm.tm_year -= 1900;           // -1900: required mktime correction 

    d_utcSec = utcFromTM(d_tm);     // update UTC seconds

    assignTM();                     // update d_tm
}
