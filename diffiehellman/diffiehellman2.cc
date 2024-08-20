#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(BigInt const &prime, size_t generator)
{
    if (prime.size() < MIN_PRIME_SIZE)
        throw exception() << "the prime must be at least " <<
                                            MIN_PRIME_SIZE << " bits long";

    d_prime = prime;
    d_generator = generator;

    cptKeys();                  // cpt d_keys containing the private and
                                // public  keys, using d_prime and d_generator
}
