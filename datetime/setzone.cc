#include "datetime.ih"

void DateTime::setZone(Zone const &zone)
{
    d_type = LOCALTIME;
    d_zone = zone;
//    Pimpl::set(this, zone);
    assignTM();    
}
