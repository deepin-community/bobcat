#include "datetime.ih"

void DateTime::Parse::setZoneShift(bool negative, int hours, int minutes)
{
    d_zoneSeconds = hours * 3600 + minutes * 60;
    if (negative)
        d_zoneSeconds = -d_zoneSeconds;
}
