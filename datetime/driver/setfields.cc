#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

void show(DateTime const &dt, char const *label)
{
    cout << 
        label << ": " << dt << "\n"
        "    dst: " << dt.dst() << "\n"
        "    hh:mm:ss: " << dt.hours() << ':' << dt.minutes() << ':' << 
                              dt.seconds() << "\n"
        "    year-month-monthdaynr: " << dt.year() << '-' << 
                                dt.month() << '-' << dt.monthDayNr() << "\n"
        "    weekday/weeknr/yearday/yeardaynr: " << 
                  dt.weekday() << '/' << dt.weekNr() << '/' << 
                  dt.yearDay() << '/' << dt.yearDayNr() << "\n"
        "\n";
}

int main()
{
    time_t now = time(0);

    DateTime utc{ now, DateTime::UTC };
    cout << "1: current UTC: " << utc << "\n\n";

    utc += tm{ 0, 0, 2, 1 };
    cout << "2: utc the next day, 2 hrs later: " << utc << "\n\n";

    DateTime dt{ now, DateTime::LOCALTIME };
    cout << "3: current local time: " << dt << ", zone shift: " << 
            dt.zone().seconds() << " seconds\n\n";

    dt.setSeconds(0);

    cout << "4: local time, 0 seconds: " << dt << "\n\n";

    dt += tm{ 0, 0, 2 };
    cout << "5a: local time, 2 hrs later: " << dt << "\n\n";

    dt += tm{ 0, 0, 2, 1 };
    cout << "5: local time, next day, 2 hrs later: " << dt << "\n\n";

    dt += chrono::hours(1);
    cout << "6: local time: add another hour: " << dt << "\n\n";


    utc.setFields(
                    tm{ 0, 0, 8, 1 }, 
                    DateTime::SECONDS | 
                    DateTime::HOURS | 
                    DateTime::MONTHDAY
                );
    show(utc, "7: utc, 1st of the month, 8 hrs, 0 sec.");

    cout << "---------------\n";

    DateTime dt1{ now, DateTime::LOCALTIME };
    cout << "8: current local time: " << dt1 << "\n\n";

    dt1.setFields(
                    tm{ 0, 0, 8, 1 }, 
                    DateTime::SECONDS | 
                    DateTime::HOURS | 
                    DateTime::MONTHDAY
                );
    show(dt1, "9: local time for 1st of the month, 8 hrs, zero seconds");

    DateTime dt2{ now, DateTime::LOCALTIME };
    dt2.setDay(dt2.monthDayNr() - 7);
    show(dt2, "10: current local time, one week ago");
}








