#include "datetime.ih"

void DateTime::setHours(int hours)
{
    setFields(TM{ 0, 0, hours }, HOURS);
}
