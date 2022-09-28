#include "main.ih"

void showLocalTime()
{
    time_t current = time(0) + thisZone + thisDST;

    tm ts;

    gmtime_r(&current, &ts);

    showTM(ts, "Local time");
}

