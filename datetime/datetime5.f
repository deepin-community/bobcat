// UTC time is ::time(0), zone shift is zoneMinutes

inline FBB::DateTime::DateTime(Zone const &zone)
:
    DateTime(::time(0), zone)   // -> 8
{}
