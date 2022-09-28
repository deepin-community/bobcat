#include "datetime.ih"

//  time: time in seconds since the epoch
//      UTC: merely time, zone = 0,             supportsDST = false
//      LOCALTIME: sets  d_thisZone (zone()),   supportsDST, d_dst: standard

DateTime::DateTime(time_t time, TimeType type)
:
    d_type(type),
    d_utcSec(time),
    d_zone(Zone::get(d_type == UTC ? "<000>" : "<001>") )
{
    assignTM();
}
