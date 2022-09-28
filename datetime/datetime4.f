// UTC time is ::time(0), zoneMinutes is localZone (in minutes)
// no dst, zone = local

inline DateTime::DateTime(std::chrono::minutes minutes)
:
    DateTime( Zone{ seconds2str(minutes.count() * 60) } )    // -> 5.f
{}
