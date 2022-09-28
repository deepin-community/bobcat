#include "datetime.ih"

// static
int DateTime::Zone::seconds(string const &spec)
{
    char sign;
    char sep;
    int hours;
    int minutes = 0;

    istringstream in{ spec };
    in >> sign >> hours >> sep >> minutes;

    int seconds = hours * 3600 + minutes * 60;

    return sign == '-' ? -seconds : seconds;    
}
