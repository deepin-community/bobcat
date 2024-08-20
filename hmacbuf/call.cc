#include "hmacbuf.ih"

void HMacBuf::call(int retValue, char const *fName)
{
    if (retValue != 1)
        throw Exception{} << "HMacBuf: EVP_MAC_" << fName << " failed";
}
