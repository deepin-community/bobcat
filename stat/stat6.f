inline Stat::Stat(Lstat, std::string const &name, std::string const &pathlist)
{
    setPath(lstat, name, pathlist);
}
