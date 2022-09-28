#include "datetime.ih"

void DateTime::Parse::fromDayName()
{
    d_in.clear();           // not starting with a year, restart extractions

    string day;
    if (not (d_in >> day))                      // #1-#3 require day
        throw 1;

    if (day.back() == ',')
        dateR();                                // format #3
    else
        fromMonth();                            // formats #1, #2
}
