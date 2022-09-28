inline FMT center(std::string const &size, unsigned precision = ~0U)
{
    return { FMT::CENTER, static_cast<unsigned>(size.length()), 
                          precision, 1 };
}
