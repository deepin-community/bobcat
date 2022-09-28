//#include "datetime.ih"
//
//void DateTime::d_tm2d_tm(int displayZone)      // shift in minutes
//{
//    d_dst = 0;
//    d_tm.tm_isdst = 0;
//
//    d_tm2utcSec();          // UTC seconds matching d_tm in d_time
//
//    setDisplayZone(zoneSeconds(displayZone));
//    utcSec2timeStruct(&d_tm, d_time);
//}
//
