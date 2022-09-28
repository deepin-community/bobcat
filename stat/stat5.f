inline Stat::Stat(std::string const &name, std::string const &pathlist)
{
    setPath(::stat, name, pathlist);
}
