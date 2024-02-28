#include "diffiehellman.ih"

BigInt const &DiffieHellman::key(std::string const &peerFileName)
{
    ifstream in = Exception::factory<ifstream>(peerFileName);

    return key(in);
}
