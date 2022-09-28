template <int power2, size_t base, size_t end, size_t begin>
inline uint64_t constexpr
    FieldType<power2, base, end, begin>::set(uint64_t src, uint64_t value)
{
    // value is:    |   A   |   B   |   C
    //                     e       b

    return src / exp1<base, end>::value            // src: A ->
                * exp1<base, end>::value +          //  A   |  ...  |   ...

           value % exp1<base, end - begin>::value   // value % b..e -> B
                 * exp1<base, begin>::value +       //  ... |   B   |   ...

           src % exp1<base, begin>::value;         //  ... |  ...  |    C
}
