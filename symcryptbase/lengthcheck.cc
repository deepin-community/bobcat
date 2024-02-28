#include "symcryptbase.ih"

void SymCryptBase::lengthCheck(char const *what, size_t required,
                                        size_t actual) const
{
    if (actual < required)
        throw Exception{} << d_cipherName << " needs " << what <<
                            " length " << required << ", got: " << actual;
}
