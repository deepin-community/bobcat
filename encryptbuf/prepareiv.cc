#include "encryptbuf.ih"

void EncryptBuf::prepareIV()
{
    if (not d_iv.empty())
        return;

    d_iv.resize(EVP_MAX_IV_LENGTH);

    IRandStream irs{ 0, 255, static_cast<size_t>(time(0)) };

    for (auto &ch: d_iv)
        setChar(ch, irs);
}
