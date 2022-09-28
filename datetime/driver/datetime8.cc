#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime utc;
    cout << "current UTC: " << utc << "\n\n";

                                        // no DST, local time: utc + 3 hrs
    DateTime dt1{ DateTime::Zone{ "3" } };            // via 5.f to 8
    cout << "Local time, 3 hours later, using Zone{ \"3\" }: " << 
                                                            dt1 << "\n\n";

    DateTime dt2{ chrono::hours{ 3 } };                // same, via 4.f to 8
    cout << "same, using chrono::hours{ 3 }: " << dt2 << "\n\n";

    DateTime dt3{ time(0) + 7 * 24 * 3600,             // one week later
                    chrono::hours{ 3 } };               
    cout << "current LOCAL time, next week: " << dt3 << "\n\n";

    DateTime dt4{ DateTime::Zone{ "3", "1" } };       // via 5.f to 8
    cout << "current LOCAL time, 3 hrs later + dst (1 hr) " << dt4 << "\n\n";

}

