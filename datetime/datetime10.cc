#include "datetime.ih"

// tm specifies a LOCALTIME time point in the time zone `zone'
// The tm_year field specifies the calendar year, so 2019 or comparable.
//
// tm's wday, yday and isdst are ignored

DateTime::DateTime(TM const &tm, Zone const &zone)
:
    DateTime(zone)                  // initialize a LOCALTIME zone
{
    d_tm = tm;
    d_tm.tm_year -= 1900;           // -1900: required mktime correction 

    d_utcSec = utcFromTM(d_tm);     // update UTC seconds

    assignTM();                     // update d_tm
}
