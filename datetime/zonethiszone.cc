#include "datetime.ih"

    // called from zoneinitialize.cc

// static
time_t DateTime::Zone::thisZone()
{
    time_t current = time(0);           // current (any utc-like time
                                        //          since the epoch)
    TM tm;
    gmtime_r(&current, &tm);            // convert to struct tm

    current -= mktime(&tm);             // this computer's zone shift

    storeIUO(s_this, seconds2str(current), tm.tm_isdst ? "1" : "");

    return current;
}
