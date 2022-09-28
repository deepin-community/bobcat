#include "datetime.ih"

void DateTime::setSeconds(int seconds)
{
    setFields(TM{ seconds }, SECONDS);
}
