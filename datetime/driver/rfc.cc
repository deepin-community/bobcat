#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

int main()
{
    time_t now = time(0);

    DateTime utc{ now, DateTime::UTC };
    cout << "UTC: " << utc << '\n' <<
            utc.rfc2822() << '\n' <<
            utc.rfc3339() << "\n\n";

    cout << utc << "\n\n";

    DateTime dt{ now, DateTime::LOCALTIME };
    cout << "LOCAL TIME: " << dt << '\n' <<
            dt.rfc2822() << '\n' <<
            dt.rfc3339() << "\n\n";

    cout << dt << "\n\n";

}



