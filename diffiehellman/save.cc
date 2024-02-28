#include "diffiehellman.ih"

    // save the prime, the generator, the public key, and the private key
void DiffieHellman::save(string const &basename) const
try
{
    ofstream out = Exception::factory<ofstream>(basename + ".pub");
    out << hex <<
            d_prime << '\n' <<
            d_generator << '\n' <<
            d_pubKey << '\n';

    if (not out)
        throw ".pub";

    int fd = open((basename + ".sec").c_str(), O_CREAT | O_RDWR,
                                               S_IRUSR | S_IWUSR);
    if (fd == -1)                           // can't open the .sec-file
        throw ".sec";

    OFdStream outSec{ fd, 512 };
    outSec << hex << d_privKey << '\n';
}
catch (char const *extension)
{
    throw exception() << "could not write " <<
                    (extension == ".pub"s ? "public" : "private") <<
                    " DH info to " << basename << extension;
}
