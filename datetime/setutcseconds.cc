#include "datetime.ih"

void DateTime::setUTCseconds(time_t utcSeconds)
{
    d_utcSec = utcSeconds;
    assignTM();
}
