#include "main.ih"

void getLocal()
{
    time_t current = time(0);               // current (any utc-like time
                                            //          since the epoch)
    struct tm ts;

    gmtime_r(&current, &ts);             // convert to struct tm

    thisZone = current - mktime(&ts);   // local zone shift

    thisDST = ts.tm_isdst == 1 ? 3600 : 0; // the computer thinks DST is used

    
    cout << "Local zone = " << thisZone / 3600. << 
                " hour(s), local DST: " << thisDST / 3600 << " hour(s)\n\n";
}
