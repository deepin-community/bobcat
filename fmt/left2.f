inline FMT left(std::string const &size, unsigned precision = ~0U)
{
    return { FMT::LEFT,  static_cast<unsigned>(size.length()), precision, 1 };
}
