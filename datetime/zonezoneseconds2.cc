#include "datetime.ih"

// static
int DateTime::Zone::zoneSeconds(std::string const &spec)
{
    setTZ(spec);
    int ret = zoneSeconds();
    resetTZ();
    return ret;
}
