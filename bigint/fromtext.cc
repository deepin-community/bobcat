#include "bigint.ih"

// conversion stops at the first character outside of the expected range of
// characters.

BigInt BigInt::fromText(string const &text, int mode)
{
    BigInt ret;

                        // determine the mode from text unless the conversion
                        // mode was explicitly specified
    if ((mode & (ios::hex | ios::oct | ios::dec)) == 0)
        mode =
            text.find_first_of("abcdefABCDEF") != string::npos ? ios::hex :
            text.find_first_of("89") == string::npos &&
                                               text[0] == '0'  ? ios::oct :
                                                                 ios::dec;
    BigInt radix(mode & ios::oct ?  8 :
                 mode & ios::hex ? 16 : 10);

    bool negative = text[0] == '-';

    int (*isFunction)(int) = mode & ios::oct ?   isoctdigit :
                             mode & ios::hex ? ::isxdigit   :
                                               ::isdigit;
    auto iter = find_if(
                    text.begin() + negative, text.end(),
                    [&, isFunction](char ch)
                    {
                        return addDigit(ch, ret, radix, isFunction);
                    }
                );

    if (iter - (text.begin() + negative) == 0)
        throw Exception{} <<
                "fromText: text does not represent a BigInt value";

    if (negative)
        ret.negate();

    return ret;
}
