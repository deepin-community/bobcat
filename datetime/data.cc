#include "datetime.ih"

char const *DateTime::s_month[] =
{
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec",
};

char const *DateTime::s_day[] =
{
    "Sun",
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat"
};

// Zone static data:
// =================

mutex DateTime::Zone::s_mutex;

unordered_map<string, unique_ptr<DateTime::Zone>> *DateTime::Zone::s_zone = 0;

time_t DateTime::Zone::s_thisZoneShift;

string DateTime::Zone::s_defaultTZ;

char const DateTime::Zone::s_utc[] = "<000>";
char const DateTime::Zone::s_this[] = "<001>";
char const DateTime::Zone::s_anon[] = "<999>";
