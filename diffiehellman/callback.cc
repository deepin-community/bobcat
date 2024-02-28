#include "diffiehellman.ih"

namespace {
    char info[] = {0, '.', '-', '+'};
}

    // . is put when a number is tested for primality
    // - is put when a prime has been found
// static
int DiffieHellman::callback(int indicator, int, BN_GENCB *)
{
    if (indicator)
        cout.put(info[indicator]).flush();
    return 1;
}
