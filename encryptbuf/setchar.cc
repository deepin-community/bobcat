#include "encryptbuf.ih"

// static
void EncryptBuf::setChar(char &ch, IRandStream &irs)
{
    int value;
    irs >> value;
    ch = value;
}

