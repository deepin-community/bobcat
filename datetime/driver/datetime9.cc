#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime utc;
    cout << "current UTC: " << utc << "\n\n";

    tm ts{  0,      // sec
            0,      // min
            19,     // hour
            4,      // month-day
            3,      // month 
            2019,   // year
         };

    DateTime dt{ ts, DateTime::UTC };
    cout << "explicitly specified UTC: 19:00:00: " << dt << "\n\n";

    DateTime dt2{ ts, DateTime::LOCALTIME };
    cout << "explicitly specified LOCAL TIME 19:00:00: " << dt2 << "\n"
            "corresponding UTC: " << dt2.utc() << "\n\n";

    cout << "time (hr explicitly set to 19):\n";
    ts.tm_mon = 10;
    DateTime dt3{ ts, DateTime::LOCALTIME };
    cout << "specified localtime 19:00:00: " << dt3 << 
                        ", dst = " << dt3.dst() << "\n"
            "corresponding UTC: " << dt3.utc() << "\n\n";
}

