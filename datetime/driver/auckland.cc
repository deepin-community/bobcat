#include <ctime>
#include <iostream>

using namespace std;

void tm2cout(tm const &ts)
{
    cout << 
            "mon "  << ts.tm_mon     <<
        ",  mday " << ts.tm_mday    <<
        ",  time " << ts.tm_hour    <<
        ':'        << ts.tm_min     <<
        ':'        << ts.tm_sec     <<
        ",  year " << ts.tm_year    <<
        ",  DST " <<  ts.tm_isdst   << '\n';
}


int main()
{
    cout << "Local reconfig to :Pacific/Auckland, not using DateTime\n\n";

    time_t now = time(0);

    setenv("TZ", ":Pacific/Auckland", 1);
    tzset();    

    tm ts;

    if (not localtime_r(&now, &ts))
    {
        cout << "Failure\n";
        return 1;
    }

    tm2cout(ts);

    cout << '\n';
}

