#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(istream &publicStream, istream &privateStream)
{
    if (not(publicStream >> hex >> d_prime >> d_generator >> d_pubKey))
        exception() << "can't read the public data file";

    BigInt privKey;
    if (not(privateStream >> hex >> d_privKey))
        exception() << "can't read the private data file";
}
