#include <iostream>
#include <ostream>
#include <ctime>
#include <unistd.h>
#include <exception>

#include <bobcat/bigint>

#include "../ldc"

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cout << "\n"
                "args: optional hex number without initial 0x\n"
                "      by default 1122334455667788aabbcc\n"
                "optional 2nd arg: radix (2 <= radix <= 36)\n"
                "                  or ':<#iterations>' for arg[2] BigInt and "
                                                        "LDC conversions\n"
                "                  (#iterations are multiplied by 1'000)\n"
                "\n";
    }

    string value = "1122334455667788aabbcc";

    if (argc > 1)
        value = argv[1];

    size_t radix = 10;
    size_t iterations = 0;

    if (argc > 2)
    {
        if (argv[2][0] != ':')           // non-default radix
            radix = stoul(argv[2]);
        else
            iterations = stoull(argv[2] + 1);
    }

    LDC digits{ value, "0123456789ABCDEF" };

    LDC ldc{ value, radix };

    cout << "radix = " << radix << "\n"
            "value = " << value << "\n"
            "digits: " << digits << "\n"
            "   LDC: " << ldc << "\n"
            "        " << ldc(3, '.') << '\n';

    BigInt bigInt = BigInt::fromText(value, ios::hex);
    cout << "BigInt: " << bigInt << '\n';

    char *bytes = bigInt.bigEndian();
    LDC ldc2(bigInt.sizeInBytes(), bytes);
    delete[] bytes;

    cout << "  LDC2: " << ldc2 << '\n';

    LDC ldc3(bigInt);
    cout << "  LDC3: " << ldc2 << '\n';

    if (iterations == 0)                // no timing
        return 0;

    ostream dummy(0);                   // dummy ostream to insert BigInts in
    dummy.setstate(ios::badbit);        // for comparison also used with LDC

    cout << "requested 1000 * " << iterations << " iterations\n";

    iterations *= 1000;

    size_t now = time(0);
    for (size_t begin = 0; begin != iterations; ++begin)
        dummy << bigInt;
    size_t done = time(0);
    cout << "BigInt conversion: " << (done - now) << " seconds\n";

    now = time(0);
    for (size_t begin = 0; begin != iterations; ++begin)
        dummy << ldc;
    done = time(0);
    cout << "LDC conversion: " << (done - now) << " seconds\n";

}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
    return 1;
}
