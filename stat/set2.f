inline bool Stat::set(Lstat, std::string const &name)
{
    return set(lstat, name);
}
