inline FMT right(std::string const &size, unsigned precision = ~0U)
{
    return { FMT::RIGHT,  static_cast<unsigned>(size.length()), precision, 1 };
}
