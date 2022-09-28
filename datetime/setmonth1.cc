#include "datetime.ih"

void DateTime::setMonth(int month)
{
           //    s  m  h  md
    setFields(TM{ 0, 0, 0, 0, month }, MONTH);
}
