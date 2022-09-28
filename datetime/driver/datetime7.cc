#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime utc;
    cout << "current UTC time: " << utc << "\n\n";

    DateTime dt1{ time(0) + 3600,   // no DST, local time: utc + 1 + 3 hrs
                  chrono::hours{ 3 } };  

    cout << "no DST, LOCAL time = UTC + 4 hours: " << dt1 << 
                ", dst = " << dt1.dst() << "\n\n";
}

