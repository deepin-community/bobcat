#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

//  The value of TZ can be one of two  formats.   The  first  format  is  a
//  string of characters that directly represent the timezone to be used:
//
//         std offset[dst[offset][,start[/time],end[/time]]]
//
//   There  are no spaces in the specification.  
//
//  The std string specifies an abbreviation for the timezone and must be
//  three or more alphabetic characters.  
//
//  When enclosed between the less-than (<) and greater-than (>) signs, the
//  characters set is expanded to include the plus (+) sign, the minus (-)
//  sign, and digits.  
//
//  The offset string immediately follows std and specifies the time value to
//  be **added** to the local time to get Coordinated Universal Time (UTC).
//
//  The offset is **positive** if the local timezone is west of the Prime
//  Meridian and negative if it is east.  The hour must be between 0 and 24,
//  and the minutes and seconds 00 and 59:
//
//      [+|-]hh[:mm[:ss]]
//
//  --------------------------------------------------------------------------
//  DST:
//
//         std offset[dst[offset][,start[/time],end[/time]]]
//
//  The  dst  string  and offset specify the name and offset for the corre‐
//  sponding daylight saving timezone. E.g.,
//
//      TZ="NZST-12:00:00NZDT-13:00:00,M10.1.0,M3.3.0"
//
//  If the offset is omitted, it defaults to one hour ahead of standard
//  time.
//
//  The  start  field  specifies when daylight saving time goes into effect
//  and the end field specifies when the change is made  back  to  standard
//  time.  These fields may have the following formats:
//
//  Jn     This  specifies  the  Julian day with n between 1 and 365.  Leap
//         days are not counted.  In this format, February 29 can't be rep‐
//         resented; February 28 is day 59, and March 1 is always day 60.
//
//  n      This  specifies  the  zero-based Julian day with n between 0 and
//         365.  February 29 is counted in leap years.
//
//  Mm.w.d This specifies day d (0 <= d <= 6) of week w (1 <= w  <=  5)  of
//         month m (1 <= m <= 12).  Week 1 is the first week in which day d
//         occurs and week 5 is the last week in which day d occurs.  Day 0
//         is a Sunday.
//
//  --------------------------------------------------------------------------
//  TIME:
//         std offset[dst[offset][,start[/time],end[/time]]]
//
//  The  time  fields  specify when, in the local time currently in effect,
//  the change to the other  time  occurs.   If  omitted,  the  default  is
//  02:00:00.
//
//  Here  is  an example for New Zealand, where the standard time (NZST) is
//  12 hours ahead of UTC, and daylight saving time (NZDT), 13 hours  ahead
//  of  UTC,  runs  from the first Sunday in October to the third Sunday in
//  March, and the changeovers happen at the default time of 02:00:00:
//      TZ="NZST-12:00:00NZDT-13:00:00,M10.1.0,M3.3.0"
//
//
//  --------------------------------------------------------------------------
//  The SECOND FORMAT specifies that the  timezone  information  should  be
//  read from a file:
//  
//      :[filespec]
//  
//  If  the  file specification filespec is omitted, or its value cannot be
//  interpreted, then Coordinated Universal Time (UTC) is used.   If  file‐
//  spec  is  given, it specifies another tzfile(5)-format file to read the
//  timezone information from.  If filespec does not begin with a '/',  the
//  file  specification  is  relative to the system timezone directory.  If
//  the colon is omitted each of the above TZ formats will be tried.
//  
//  Here's an example, once more for New Zealand:
//  
//      TZ=":Pacific/Auckland"

//      std offset[dst[offset][,start[/time],end[/time]]]
//      TZ=":Pacific/Auckland"
// Zone specifications:

//        string:   name of a previously defined time zone
//
//        [string,] string: specification as ":Pacific/Auckland"
//
//        [string,] string: [+|-]hh[:mm[:ss]]            -- zone shift
//                                                           no DST
//        [string,] string, string2                      -- string2:
//                                                           DST correction
//              ("3", "1" means: std shift +3 hours, 1 hour DST shift)
//
//        [string,] string, string2, string3, string4,
//          string3: begin  of DST
//          string4: end moment of DST
//
//          dst spec = "m.w.d[/time]"
//              m: month (1..12), w:week (1..5), d: day (0: Sunday)
//              specify week 1 for the first week in which d occurs
//              specify week 5 for the last week in which d occurs
//              time: by default 2:0:0 current *local* time (not considering
//                      dst at the end of the dst) when the dst starts/ends
//  An optional initial string defines the name of the time zone
//  No zone specification means: the computer's currently defined time zone is
//  used. 
//      


time_t utcSec(struct tm *tm, char const *tzSpec)
{
    time_t ret;
    char *tz;
    string tzStr;

    tz = getenv("TZ");          // save the current TZ info
    if (tz)
        tzStr = tz;


    setenv("TZ", tzSpec, 1);    // use tzSpec as TZ (empty is UTC)
    tzset();

    ret = mktime(tm);           // compute the UTC time fm localtime in tm

    if (tm->tm_isdst)
        ret -= 3600;            // for now: assume std 1 hour positive shift

    if (tzStr.empty())
        unsetenv("TZ");    
    else
        setenv("TZ", tzStr.c_str(), 1);

    tzset();
    return ret;
}

tm *local_r(time_t *utcSec, struct tm *tm, char const *tzSpec)
{
    char *tz;
    string tzStr;

    tz = getenv("TZ");          // save the current TZ info
    if (tz)
        tzStr = tz;

    setenv("TZ", tzSpec, 1);    // use tzSpec as TZ (empty is UTC)
    tzset();

    localtime_r(utcSec, tm);

    if (tzStr.empty())
        unsetenv("TZ");    
    else
        setenv("TZ", tzStr.c_str(), 1);

    tzset();
    return tm;
}

time_t zoneShift()
{
    char *tz;
    string tzStr;

    tz = getenv("TZ");          // save the current TZ info
    if (tz)
        tzStr = tz;

    tm ts;
//    setenv("TZ", ":Europe/Amsterdam", 1);    // use tzSpec as TZ (empty is UTC)
    setenv("TZ", ":Asia/Calcutta", 1);    // use tzSpec as TZ (empty is UTC)
    tzset();

    time_t ret = 0;
    gmtime_r(&ret, &ts);

    ret = mktime(&ts);

    if (tzStr.empty())
        unsetenv("TZ");    
    else
        setenv("TZ", tzStr.c_str(), 1);

    tzset();
    return ret;
}

int main()
{
    cout << zoneShift() << '\n';

    tm src{  0,          // sec
            0,          // min
            19,         // hour -> current zone = CET -> UTC = 18
                        //         (not considering DST)
            4,          // month-day
            3,          // month 
            2019 - 1900,   // year
         };

    tm ts = src;

    time_t utc = mktime(&ts);

    cout << utc << " dst: " << ts.tm_isdst << '\n';
    gmtime_r(&utc, &ts);
    DateTime::tm2cout("UTC time: ", ts);

    localtime_r(&utc, &ts);
    DateTime::tm2cout("Local time: ", ts);

    local_r(&utc, &ts, "CET-1:00DST");
    DateTime::tm2cout("Local time via local_r: ", ts);


    ts = src;
    ts.tm_hour += 5 - 1;        // Kolkata: +5:30 UTC
    ts.tm_min += 30;

    utc = utcSec(&ts, ":Asia/Calcutta");
    cout << utc << " dst: " << ts.tm_isdst << '\n';
    gmtime_r(&utc, &ts);
    DateTime::tm2cout("UTC time: ", ts);


    ts = src;
    ts.tm_hour += 5 - 1;        // Kolkata: +5:30 UTC
    ts.tm_min += 30;

    utc = utcSec(&ts, "ZONE-05:30");
    cout << utc << " dst: " << ts.tm_isdst << '\n';
    gmtime_r(&utc, &ts);
    DateTime::tm2cout("UTC time: ", ts);

    ts = src;
    ts.tm_hour += 5 - 1;        // Kolkata: +5:30 UTC
    ts.tm_min += 30;

    utc = utcSec(&ts, "<001>-05:30");
    cout << "same, using zone name <001>:\n";
    cout << utc << " dst: " << ts.tm_isdst << '\n';
    gmtime_r(&utc, &ts);
    DateTime::tm2cout("UTC time: ", ts);

    ts = src;
    ts.tm_hour += 5 - 1;        // Any other: +5:00 UTC

    utc = utcSec(&ts, "ZONE-05:00DST");     // with a std DST specification
    cout << utc << " dst: " << ts.tm_isdst << '\n';
    gmtime_r(&utc, &ts);
    DateTime::tm2cout("UTC time, with DST: ", ts);
}


/*
time_t my_timegm(struct tm *tm)
{
    time_t ret;
    char *tz;
    string tzStr;

    tz = getenv("TZ");          // get the current TZ info
    if (tz)
        tzStr = tz;

    setenv("TZ", "", 1);        // clear the TZ variable
    tzset();

    ret = mktime(tm);           // compute the UTC time fm localtime in tm
    if (tz) 
    {
         setenv("TZ", tz, 1);
         free(tz);
    } 
    else
        unsetenv("TZ");
    tzset();
    return ret;
}
*/

