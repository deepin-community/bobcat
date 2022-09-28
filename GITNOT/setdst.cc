#include "datetime.ih"

int DateTime::setDst(time_t time)
{
    TM ts;
    return d_dst = localtime_r(&time, &ts)->tm_isdst ? 3600 : 0;
}
