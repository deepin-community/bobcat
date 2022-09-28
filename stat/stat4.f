inline Stat::Stat(Lstat, std::string const &name)
:
    d_name(name)
{
    init(lstat);
}
