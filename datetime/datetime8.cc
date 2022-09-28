#include "datetime.ih"

// time provides UTC time in seconds, zone sets zone + DST.

DateTime::DateTime(time_t time, Zone const &zone)
:
    d_utcSec(time)
{
    setZone(zone);
}
