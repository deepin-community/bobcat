template <size_t base, size_t pwr>
struct exp1
{
    enum
    {
        value = base * exp1<base, pwr - 1>::value
    };
};

template <size_t base>
struct exp1<base, 0>
{
    enum
    {
        value = 1
    };
};
