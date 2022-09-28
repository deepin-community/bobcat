#include "decryptbuf.ih"


//     int EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out,
//                           int *outl, const unsigned char *in, int inl);
//
//
//     EVP_EncryptUpdate() encrypts inl bytes from the buffer in and writes
//     the encrypted version to out. This function can be called multiple
//     times to encrypt successive blocks of data. The amount of data written
//     depends on the block alignment of the encrypted data: as a result the
//     amount of data written may be anything from zero bytes to (inl +
//     cipher_block_size - 1) so out should contain sufficient room. The
//     actual number of bytes written is placed in outl. It also checks if in
//     and out are partially overlapping, and if they are 0 is returned to
//     indicate failure.
//
//      Analogously (?):
//     EVP_DecryptUpdate() decrypts inl bytes from the buffer in and writes
//     the decrypted version to out. This function can be called multiple
//     times to decrypt successive blocks of data. 
//
//     EVP_DecryptInit_ex(), EVP_DecryptUpdate() and EVP_DecryptFinal_ex() are
//     the corresponding decryption operations. EVP_DecryptFinal() will return
//     an error code if padding is enabled and the final block is not
//     correctly formatted. The parameters and restrictions are identical to
//     the encryption operations except that if padding is enabled the
//     decrypted data buffer out passed to EVP_DecryptUpdate() should have
//     sufficient room for (inl + cipher_block_size) bytes unless the cipher
//     block size is 1 in which case inl bytes is sufficient.


void DecryptBuf::flushBuffer()
{
    size_t srcLen = pptr() - pbase();

    int decryptedLen;
    if (
        not EVP_DecryptUpdate(d_ctx, 
                ucharPtr(d_decrypted), &decryptedLen, 
                ucharPtr(), srcLen)
    )
    {
        ERR_print_errors_fp(stderr);
        throw 1;
    }

    d_outStream.write(&d_decrypted[0], decryptedLen);
    setp();
}

