inline void Pattern::newRegex(std::string const &pattern, int options)
{
    d_regex = new Regex(pattern, options);
}
