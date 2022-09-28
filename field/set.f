template <size_t base, size_t end, size_t begin>
inline uint64_t constexpr Field<base, end, begin>::set(uint64_t src,
                                                       uint64_t value)
{
    return FieldType<((base - 1) & base) == 0, base, end, begin>::set(src,
                                                                      value);
}
