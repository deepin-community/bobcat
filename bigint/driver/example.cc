#include <iostream>
#include <bobcat/bigint>

using namespace std;
using namespace FBB;

int main()
{
    BigInt value(BigInt::prime(100));
    BigInt mod(BigInt::rand(50));
    BigInt inverse(value.inverseModc(mod));

    cout << '(' << value << " * " << inverse << ") % " << mod << " = " <<
             (    value       *      inverse     ) %      mod << '\n';
}

// shows:
// (1258586273445895786081124957771 * 828997573545038) %
//                                                  1007205247048889 = 1
