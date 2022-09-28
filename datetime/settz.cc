#include "datetime.ih"

// static
void DateTime::setTZ(string const &spec)
{
    setenv("TZ", spec.c_str(), 1);  // use tzSpec as TZ (empty is UTC)
    tzset();
}
