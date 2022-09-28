inline std::ostream &operator<<(std::ostream &out, FMT const &fmt)
{
    return fmt.insert(out);
}
