#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

int main()
{
    DateTime utc{ time(0), DateTime::UTC };
    cout << "current UTC time: " << utc << ", dst = " << utc.dst() << "\n\n";

    DateTime utcCopy{ utc };
    cout << "          a copy: " << utcCopy << "\n\n";


    DateTime local{ DateTime::LOCALTIME };
    cout << "current LOCAL time: " << local << 
                                        ", dst = " << local.dst() << "\n\n";

    DateTime localCopy{ local };
    cout << "            a copy: " << utcCopy << "\n\n";


    DateTime moved{ std::move(localCopy) };
    cout << "moved from existing object: " << moved << 
                        ", dst = " << moved.dst() << 
                        ", zone spec: " << moved.zone().spec() << "\n\n";

    cout << "existing object after move: " << localCopy << 
                        ", dst = " << moved.dst() << 
                        ", zone spec: " << moved.zone().spec() << "\n\n";

}

