#include "datetime.ih"

// static
time_t DateTime::Zone::initialize()
{
    storeIUO(s_utc, ":");               // store the UTC zone
    storeIUO("CET", "+1:00", "+1:00");
    time_t ret = thisZone();            // defines zone 'this'

    char *tz = getenv("TZ");            // save the current TZ info
    if (tz)
        s_defaultTZ = tz;

    return ret;
}


