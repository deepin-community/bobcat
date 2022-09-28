#include "main.ih"

void showDesiredTime()
{
    if (not showDesired)
        return;

    time_t current = time(0) + desiredZone + desiredDST;

    tm ts;

    gmtime_r(&current, &ts);

    cout << "UTC time shift: " <<
                showpos <<
                setw(3) << internal <<
                            (desiredZone + desiredDST) / 3600 <<
            noshowpos <<
                setw(2) << abs(desiredZone + desiredDST) % 3600 / 60 << '\n';

    showTM(ts, "Desired time");
}

