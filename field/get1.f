template <size_t base, size_t end, size_t begin>
inline uint64_t constexpr FieldType<1, base, end, begin>::get(uint64_t value)
{
    return (value & ((1 << end * exp2<base>::value) - 1))
           >> (begin * exp2<base>::value);
}
