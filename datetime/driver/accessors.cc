#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

void show(DateTime const &dt, char const *label)
{
    cout << 
        label << ": " << dt << "\n"
        "dst: " << dt.dst() << "\n"
        "hh:mm:ss: " << dt.hours() << ':' << dt.minutes() << ':' << 
                        dt.seconds() << "\n"
        "year-month-monthdaynr: " << dt.year() << '-' << dt.month() << '-' <<
                                     dt.monthDayNr() << "\n"
        "weekday/weeknr/yearday/yeardaynr: " << 
            dt.weekday() << '/' << dt.weekNr() << '/' << 
            dt.yearDay() << '/' << dt.yearDayNr() << "\n"
        "\n";
}

int main()
{
    time_t now = time(0);

    DateTime utc{ now, DateTime::UTC };
    show(utc, "Current UTC time");

    DateTime local{ utc.thisTime() };

    cout << "The COMPUTER'S LOCAL TIME: " << local << '\n';

    DateTime dt{ now, DateTime::LOCALTIME };
    show(dt, "Current LOCAL TIME");

    DateTime utc2{ dt.utc() };
    cout << "UTC obtained from LOCAL TIME: " << utc2 << '\n';

    DateTime jan1{ "2019-01-01 13:00:00+01:00", DateTime::LOCALTIME };
    cout << "Jan 1, 1919, 13:00h: " << jan1 << '\n';
    show(jan1, "Jan 1, details:");

    cout << "\nOptionally rerun specifying another time zone specification\n"
            "\n";
}


