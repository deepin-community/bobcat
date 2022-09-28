#include "main.ih"

void showTM(tm const &ts, char const *label)
{
    cout << label << ": hh:mm " <<
                ts.tm_hour << ':' << setw(2) << setfill('0') << 
                ts.tm_min << "\n\n";
}
