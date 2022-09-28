#include "datetime.ih"

void DateTime::setMinutes(int minutes)
{
    setFields(TM{ 0, minutes }, MINUTES);
}
