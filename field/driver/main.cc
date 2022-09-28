#include <iostream>

#include "../field"

using namespace std;
using namespace FBB;

int main()
{
    cout << Field<10, 3, 1>::get(12345) << "    <- 34\n";
    cout << Field<10, 2, 0>::get(12345) << "    <- 45\n";

    cout << Field<10, 3, 1>::set(12345, 99)  << "    <- 12995\n";
    cout << Field<10, 2, 0>::set(12345, 999) << "    <- 12399\n";

    cout << hex;

    cout << Field<16, 3, 1>::get(0xabcd) << "   <- bc\n";
    cout << Field<16, 2, 0>::get(0xabcd) << "   <- cd\n";

    cout << Field<16, 3, 1>::set(0xabcd, 0x11)  << "     <- a11d\n";
    cout << Field<16, 2, 0>::set(0xabcd, 0x222) << "     <- ab22\n";

    cout << oct;
    cout << Field<8, 3, 1>::get(076543) << "    <- 54\n";
    cout << Field<8, 2, 0>::get(076543) << "    <- 43\n";
}



