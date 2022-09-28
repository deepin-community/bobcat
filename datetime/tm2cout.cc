#include "datetime.ih"

// static
void DateTime::tm2cout(char const *label, TM const &ts)
{
    cout << label <<
        ",  mon "  << ts.tm_mon     <<
        ",  mday " << ts.tm_mday    <<
        ",  time " << ts.tm_hour    <<
        ':'        << ts.tm_min     <<
        ':'        << ts.tm_sec     <<
        ",  year " << ts.tm_year    <<
        ",  DST " <<  ts.tm_isdst   << '\n';
}
