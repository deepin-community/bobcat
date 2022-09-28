#include "datetime.ih"

DateTime &DateTime::operator-=(chrono::seconds seconds)
{
    d_utcSec -= seconds.count();
    assignTM();

    return *this;
}
