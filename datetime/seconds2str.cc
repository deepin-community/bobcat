#include "datetime.ih"

// static
std::string DateTime::seconds2str(time_t seconds)
{
    char sign = '+';

    if (seconds < 0)
    {
        sign = '-';
        seconds = -seconds;
    }

    seconds /= 60;                      // ignore the seconds, use the minutes

                                        // zoneshift as -hh:mm
    return sign + to_string(seconds / 60) + ':' + to_string(seconds % 60);
}

