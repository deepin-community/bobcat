#include "datetime.ih"

    // obtain UTC seconds given zone and spec. in TM
    // use assignTM to set TM from utc seconds + current zone
time_t DateTime::utcFromTM(TM &tm) const
{
    time_t ret = utcForZone(zone().spec(), tm);

    if (tm.tm_isdst)
        ret -= zone().dstSeconds();

    return ret;
}

