#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(size_t primeLength, size_t generator,
                             bool progress)
:
    DiffieHellman(prime(primeLength, true, progress), generator)
{}
