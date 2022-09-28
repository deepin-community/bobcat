inline FMT right(unsigned size, unsigned precision = ~0U)
{
    return { FMT::RIGHT,  size, precision, 1 };
}
