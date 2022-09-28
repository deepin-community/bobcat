template <size_t base>
struct exp2
{
    enum
    {
        value = 1 + exp2<base / 2>::value
    };
};

template <>
struct exp2<1>
{
    enum
    {
        value = 0
    };
};
