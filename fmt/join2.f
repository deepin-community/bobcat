    // join all remaining columns

inline FMT join(FMT::Align align, unsigned precision = ~0U)
{
    return join(~0U, align, precision);
}

