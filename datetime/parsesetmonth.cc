#include "datetime.ih"

void DateTime::Parse::setMonth(string const &mon)
{
    d_tm.tm_mon = stdFind(s_month, 12, mon);
}
