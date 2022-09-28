inline FMT left(unsigned size, unsigned precision = ~0U)
{
    return { FMT::LEFT,  size, precision, 1 };
}
