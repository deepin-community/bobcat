#include "datetime.ih"

void DateTime::setYear(unsigned year)
{
                //s  m  h  md m
    setFields(TM{ 0, 0, 0, 0, 0, static_cast<int>(year) }, YEAR);
}
