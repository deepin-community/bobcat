//#include "datetime.ih"
//
//void DateTime::utcSec2timeStruct(TM *ts, time_t time)
//{
//    time += d_zone;     // add local time shift (if any)
//
//    tm2cout(__FILE__" pre", d_tm);
//
//    d_ok = gmtime_r(&time, ts);
//
//    tm2cout(__FILE__, d_tm);
//
//    ts->tm_isdst = d_dst != 0;
//}
//
//
