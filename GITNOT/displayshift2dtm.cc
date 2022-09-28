//#include "datetime.ih"
//
//void DateTime::displayShift2d_tm()
//{
//    if (d_type == UTC)
//    {
//        d_dst = 0;
//        setDisplayZone(0);
//    }
//    else
//    {
//        time_t shift = defaultDisplayZone() + dstCorrection();
//        d_time -= shift;
//        setDisplayZone(shift);
//    }
//
//    utcSec2timeStruct(&d_tm, d_time);
//}
//
