#include "datetime.ih"

// static
void DateTime::resetTZ()
{
    if (Zone::defaultTZ().empty())
        unsetenv("TZ");    
    else
        setenv("TZ", Zone::defaultTZ().c_str(), 1);

    tzset();
}
