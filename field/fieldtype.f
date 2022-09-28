template <int power2, size_t base, size_t end, size_t begin>
struct FieldType
{
    static constexpr uint64_t set(uint64_t src, uint64_t value);    // 0.f
    static constexpr uint64_t get(uint64_t value);                  // 0.f
};

    // handle get/set if base is a pure power of 2:
    //
template <size_t base, size_t end, size_t begin>
struct FieldType<1, base, end, begin>
{
    static constexpr uint64_t set(uint64_t src, uint64_t value);    // 1.f
    static constexpr uint64_t get(uint64_t value);                  // 1.f
};
