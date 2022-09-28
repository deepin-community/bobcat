//#include "datetime.ih"
//
//int DateTime::dstCorrection(bool *ok) const
//{
//    TM ts;
//
//    tzset();                // see the localtime_r manpage: tzset() required
//    TM *ret =  localtime_r(&d_time, &ts);
//
//    if (not (*ok = ret))    // 0: can't compute
//        return 0;
//
//    return ts.tm_isdst == 1 ? 3600 : 0;
//}
//
