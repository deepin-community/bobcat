#include "decryptbuf.ih"

bool DecryptBuf::setRounds(size_t nRounds)
{
    return EVP_CIPHER_CTX_ctrl(d_ctx, EVP_CTRL_SET_RC5_ROUNDS, nRounds, 0);
}
