#include "datetime.ih"

// static
DateTime::Zone const &DateTime::Zone::get(std::string const &name)
{
    lock_guard<mutex> lg{ s_mutex };

    if (s_zone == 0)
    {
        s_zone = new ZoneMap;           // 1st time: allocate s_zone
        s_thisZoneShift = initialize(); // and initialize
    }

    auto iter = s_zone->find(name);

    if (iter == s_zone->end())
        throw Exception{ 1 } << "Unknown Zone `" << name << '\'';

    return *(iter->second);    
}
