template <size_t base, size_t end, size_t begin>
inline uint64_t constexpr
    FieldType<1, base, end, begin>::set(uint64_t src, uint64_t value)
{
        // consider src as |   C   |   B   |   A   |
        //                         e       b

    return
        (
            src &
            (
                ~(                                          // all C bits
                    (
                        (1 << end * exp2<base>::value) - 1  // (all B, A bits)
                    )
                )
                |                                           // and also:
                (
                    (1 << begin * exp2<base>::value) - 1    // all A bits
                )
            )
        )
        |                                                   // and also:
        (
            (
                value
                &
                (                                       // # bits from b..e
                    (1 << (end - begin) * exp2<base>::value) - 1
                )
            )                                   // value's at most b..e bits
            << (begin * exp2<base>::value)      // moved into b's offset
        );
}
