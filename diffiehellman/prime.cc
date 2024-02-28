#include "diffiehellman.ih"

// static
BigInt DiffieHellman::prime(size_t primeLength, bool safe, bool progress)
{
    BN_CTX *ctx = BN_CTX_new();

    BigInt ret;

    BN_GENCB *cb = 0;

    if (progress)
    {
        cb = BN_GENCB_new();
        BN_GENCB_set(cb, callback, 0);
    }

    bool ok = BN_generate_prime_ex2(
                        const_cast<BIGNUM *>(&ret.bignum()),
                        primeLength,
                        safe,
                        0, 0,                       //  add, rem
                        progress ? cb : 0,
                        ctx);

    BN_GENCB_free(cb);
    BN_CTX_free(ctx);

    if (not ok)
        throw exception() << "BN_generate_prime failed";

    return ret;
}

    // If add is NULL the returned prime number will have exact bit length
    // bits with the top most two bits set.
    //
    // If ret is not NULL, it will be used to store the number.
    //
    // If cb is not NULL, it is used as follows:
    //
    // • BN_GENCB_call(cb, 0, i) is called after generating the i-th potential
    //   prime number.
    //
    // • While the number is being tested for primality, BN_GENCB_call(cb, 1,
    //   j) is called as described below.
    //
    // • When a prime has been found, BN_GENCB_call(cb, 2, i) is called.
    //
    // • The callers of BN_generate_prime_ex() may call BN_GENCB_call(cb, i,
    //   j) with other values as described in their respective man pages; see
    //   "SEE ALSO".
    //
    // The prime may have to fulfill additional requirements for use in
    // Diffie-Hellman key exchange:
    //
    // If add is not NULL, the prime will fulfill the condition p % add == rem
    // (p % add == 1 if rem == NULL) in order to suit a given generator.
    //
    // If safe is true, it will be a safe prime (i.e. a prime p so that
    // (p-1)/2 is also prime). If safe is true, and rem == NULL the condition
    // will be p % add == 3.  It is recommended that add is a multiple of 4.
    //
    // The random generator must be seeded prior to calling
    // BN_generate_prime_ex().  If the automatic seeding or reseeding of the
    // OpenSSL CSPRNG fails due to external circumstances (see RAND(7)), the
    // operation will fail.  The random number generator configured for the
    // OSSL_LIB_CTX associated with ctx will be used.


    // int BN_generate_prime_ex2(BIGNUM *ret, int bits, int safe,
    //               const BIGNUM *add, const BIGNUM *rem, BN_GENCB *cb,
    //                            BN_CTX *ctx);
