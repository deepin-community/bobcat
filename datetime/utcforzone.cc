#include "datetime.ih"

// static
time_t DateTime::utcForZone(std::string const &zoneSpec, TM &tm)
{
    setTZ(zoneSpec);

    if (zoneSpec.empty())
        tm.tm_isdst = 0;

    time_t ret = mktime(&tm);
    resetTZ();

    return ret;
}

