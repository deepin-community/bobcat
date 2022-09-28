template <int power2, size_t base, size_t end, size_t begin>
inline uint64_t constexpr
    FieldType<power2, base, end, begin>::get(uint64_t value)
{
    return value / exp1<base, begin>::value
                 % exp1<base, end - begin>::value;
}
