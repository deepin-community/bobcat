#include "datetime.ih"

void DateTime::setDay(int day)
{
    setFields(TM{ 0, 0, 0, day }, MONTHDAY);
}
