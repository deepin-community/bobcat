
#include "ecdh.ih"

// static
string ECDH::lastErrorString() 
{
    return std::get<1>(lastError());
}
