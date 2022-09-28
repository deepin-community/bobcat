inline FMT center(unsigned size, unsigned precision = ~0U)
{
    return { FMT::CENTER,  size, precision, 1 };
}
