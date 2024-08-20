#include <iostream>

#include <bobcat/ldc>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    string value = "1122334455667788aabbcc";

    size_t radix = 10;

    LDC digits{ value, "0123456789ABCDEF" };

    LDC ldc{ value, radix };

    cout << "radix = " << radix << "\n"
            "value = " << value << "\n"
            "digits: " << digits << "\n"
            "   LDC: " << ldc << "\n"
            "        " << ldc(3, '.') << '\n';
}

// shows:
//     radix = 10
//     value = 1122334455667788aabbcc
//     digits: 1122334455667788AABBCC
//        LDC: 20713245101768454273940428
//             20.713.245.101.768.454.273.940.428
