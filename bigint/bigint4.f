template<typename Type>
BigInt::BigInt(Type value)
:
    d_bn(BN_new())
{
    bool negative = value < 0;
    if (negative)
        value = -value;

    BN_set_word(d_bn, static_cast<unsigned long>(value));

    if (negative)
        negate();
}    
